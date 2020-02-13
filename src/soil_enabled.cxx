/*
 * MicroHH
 * Copyright (c) 2011-2017 Chiel van Heerwaarden
 * Copyright (c) 2011-2017 Thijs Heus
 * Copyright (c) 2014-2017 Bart van Stratum
 *
 * This file is part of MicroHH
 *
 * MicroHH is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * MicroHH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with MicroHH.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdio>
#include <iostream>

#include "master.h"
#include "grid.h"
#include "fields.h"
#include "stats.h"
#include "cross.h"
#include "constants.h"
#include "netcdf_interface.h"

#include "soil.h"
#include "soil_enabled.h"

namespace
{
    template<typename TF>
    void init_soil_homogeneous(
            TF* const restrict soil_fld, const TF* const restrict soil_prof,
            const int istart, const int iend,
            const int jstart, const int jend,
            const int kstart, const int kend,
            const int isize, const int ijsize)
    {
        for (int k=kstart; k<kend; ++k)
            for (int j=jstart; j<jend; ++j)
                #pragma ivdep
                for (int i=istart; i<iend; ++i)
                {
                    const int ijk = i + j*isize + k*ijsize;
                    soil_fld[ijk] = soil_prof[k];
                }
    }

    template<typename TF>
    void calculate_grid(
            std::vector<TF>& z, std::vector<TF>& zh,
            std::vector<TF>& dz, std::vector<TF>& dzh,
            std::vector<TF>& dzi, std::vector<TF>& dzhi,
            const TF zsize, const int ktot)
    {

        // Calculate half level heights
        for (int k=1; k<ktot; ++k)
            zh[k] = 0.5*(z[k-1] + z[k]);

        zh[ktot] = 0.;
        zh[0   ] = zsize;

        // Calculate grid spacing
        for (int k=0; k<ktot; ++k)
            dz[k] = zh[k+1] - zh[k];

        for (int k=1; k<ktot; ++k)
            dzh[k] = z[k] - z[k-1];

        dzh[ktot] = 2*-z[ktot-1];
        dzh[0   ] = 2*(z[0] - zh[0]);

        // Inverse grid spacings
        for (int k=0; k<ktot; ++k)
            dzi[k] = 1./dz[k];

        for (int k=0; k<ktot+1; ++k)
            dzhi[k] = 1./dzh[k];
    }

}


template<typename TF>
Soil_enabled<TF>::Soil_enabled(Master& masterin, Grid<TF>& gridin, Fields<TF>& fieldsin, Input& inputin) : 
    Soil<TF>(masterin, gridin, fieldsin, inputin)
{
    sw_soil = Soil_type::Enabled;

    // Read the soil settings from the ini file
    ktot  = inputin.get_item<int>("soil", "ktot", "");
    zsize = inputin.get_item<TF>("soil", "zsize", "");

    sw_interactive = inputin.get_item<bool>("soil", "sw_interactive", "", false);
    sw_homogeneous = inputin.get_item<bool>("soil", "sw_homogeneous", "", true);

    // Checks on input & limitations
    if (sw_interactive)
        throw std::runtime_error("Interactive soil not (yet) implemented");
    if (!sw_homogeneous)
        throw std::runtime_error("Heterogeneous soil input not (yet) implemented");

    // Create soil fields (temperature and volumetric water content)
    t_soil     = std::make_shared<Soil_field<TF>>(master, grid);
    theta_soil = std::make_shared<Soil_field<TF>>(master, grid);
}

template<typename TF>
Soil_enabled<TF>::~Soil_enabled()
{
}

template<typename TF>
void Soil_enabled<TF>::init()
{
    /*
       Allocate/resize the soil fields, properties, and grid definition.
    */
    auto& gd = grid.get_grid_data();
    const int ncells_soil = gd.ijcells * ktot;
    const int ncells_soil_h = gd.ijcells * (ktot+1);

    // Init prognostic soil fields
    t_soil->init(ktot);
    theta_soil->init(ktot);

    // Resize the vectors which hold the vertical grid info
    z.resize(ktot);
    dz.resize(ktot);
    dzi.resize(ktot);
    zh.resize(ktot+1);
    dzh.resize(ktot+1);
    dzhi.resize(ktot+1);

    // Resize the vectors which contain the soil properties
    soil_index.resize(ncells_soil);

    if (sw_interactive)
    {
        diffusivity.resize(ncells_soil);
        diffusivity_h.resize(ncells_soil_h);
        conductivity.resize(ncells_soil);
        conductivity_h.resize(ncells_soil_h);
        source.resize(ncells_soil);
    }
}

template<typename TF>
void Soil_enabled<TF>::create_cold_start(Input& input, Netcdf_handle& input_nc)
{
    /*
       Create the prognostic soil fields, initialised either
       homogeneous from the input NetCDF file, or heterogeneous
       from "other" (yet to be defined..) sources.
       This routine is only called in the `init` phase of the model (from model.cxx),
       in the `run` phase these fields are read from the restart files.
     */
    auto& gd = grid.get_grid_data();

    // Init the soil variables
    if (sw_homogeneous)
    {
        // Read initial profiles from input NetCDF file
        Netcdf_group& soil_group = input_nc.get_group("soil");

        std::vector<TF> t_prof(ktot);
        std::vector<TF> theta_prof(ktot);

        soil_group.get_variable(t_prof, "t_soil", {0}, {ktot});
        soil_group.get_variable(theta_prof, "theta_soil", {0}, {ktot});

        // Initialise soil as spatially homogeneous
        const int kstart_soil = 0;
        const int kend_soil = ktot;

        init_soil_homogeneous(
                t_soil->fld.data(), t_prof.data(),
                gd.istart, gd.iend,
                gd.jstart, gd.jend,
                kstart_soil, kend_soil,
                gd.icells, gd.ijcells);

        init_soil_homogeneous(
                theta_soil->fld.data(), theta_prof.data(),
                gd.istart, gd.iend,
                gd.jstart, gd.jend,
                kstart_soil, kend_soil,
                gd.icells, gd.ijcells);
    }
}

template<typename TF>
void Soil_enabled<TF>::create_fields_grid_stats(
        Input& input, Netcdf_handle& input_nc, Stats<TF>& stats, Cross<TF>& cross)
{
    /*
       Create/set the non-prognostic fields (soil type, ...) from the input files,
       calculate/define the soil grid, and init the soil statistics and cross-sections.
    */
    auto& gd = grid.get_grid_data();

    // Get full level grid height (depth) from input NetCDF, and calculate vertical grid
    input_nc.get_variable(z, "z_soil", {0}, {ktot});
    calculate_grid(z, zh, dz, dzh, dzi, dzhi, zsize, ktot);

    // Init soil properties
    if (sw_homogeneous)
    {
        Netcdf_group& soil_group = input_nc.get_group("soil");
        std::vector<int> soil_index_prof(ktot);
        soil_group.get_variable<int>(soil_index_prof, "soil_index", {0}, {ktot});

        const int kstart_soil = 0;
        const int kend_soil = ktot;

        init_soil_homogeneous<int>(
                soil_index.data(), soil_index_prof.data(),
                gd.istart, gd.iend,
                gd.jstart, gd.jend,
                kstart_soil, kend_soil,
                gd.icells, gd.ijcells);
    }

    // Init the soil statistics
    if (stats.get_switch())
    {
        std::string group_name = "soil"; 

        // Add soil dimensions to each of the statistics masks
        auto& masks = stats.get_masks();
        for (auto& mask : masks)
        {
            auto& m = mask.second;

            // Add dimensions to NetCDF file
            m.data_file->add_dimension("zs",  ktot);
            m.data_file->add_dimension("zsh", ktot+1);

            // Write the attributes
            Netcdf_variable<TF> zs_var = m.data_file->template add_variable<TF>("zs", {"zs"});
            zs_var.add_attribute("units", "m");
            zs_var.add_attribute("long_name", "Full level soil height");

            Netcdf_variable<TF> zsh_var = m.data_file->template add_variable<TF>("zsh", {"zsh"});
            zsh_var.add_attribute("units", "m");
            zsh_var.add_attribute("long_name", "Half level soil height");

            // Write the grid levels
            zs_var .insert(z,  {0});
            zsh_var.insert(zh, {0});

            m.data_file->sync();
        }

        // Add the statistics variables
        stats.add_prof("t_soil", "Soil temperature", "K", "zs", group_name);
        stats.add_prof("theta_soil", "Soil volumetric water content", "-", "zs", group_name);
    }
}

template<typename TF>
void Soil_enabled<TF>::exec_stats(Stats<TF>& stats)
{
    auto& gd = grid.get_grid_data();
}

template<typename TF>
void Soil_enabled<TF>::save_prognostic_fields(const int itime)
{
    auto field3d_io = Field3d_io<TF>(master, grid);
    auto& gd = grid.get_grid_data();
    const TF no_offset = 0.;
    const int kstart = 0;
    int nerror = 0;

    auto tmp1 = fields.get_tmp();
    auto tmp2 = fields.get_tmp();

    // Soil temperature
    char filename[256];
    std::sprintf(filename, "%s.%07d", "t_soil", itime);
    master.print_message("Saving \"%s\" ... ", filename);

    if (field3d_io.save_field3d(
                t_soil->fld.data(),
                tmp1->fld.data(), tmp2->fld.data(),
                filename, no_offset,
                kstart, ktot))
    {
        master.print_message("FAILED\n");
        ++nerror;
    }
    else
        master.print_message("OK\n");

    // Soil moisture
    std::sprintf(filename, "%s.%07d", "theta_soil", itime);
    master.print_message("Saving \"%s\" ... ", filename);

    if (field3d_io.save_field3d(
                theta_soil->fld.data(),
                tmp1->fld.data(), tmp2->fld.data(),
                filename, no_offset,
                kstart, ktot))
    {
        master.print_message("FAILED\n");
        ++nerror;
    }
    else
        master.print_message("OK\n");

    fields.release_tmp(tmp1);
    fields.release_tmp(tmp2);

    master.sum(&nerror, 1);

    if (nerror)
        throw std::runtime_error("Error saving soil fields");
}

template<typename TF>
void Soil_enabled<TF>::load_prognostic_fields(const int itime)
{
    auto field3d_io = Field3d_io<TF>(master, grid);
    auto& gd = grid.get_grid_data();
    const TF no_offset = 0.;
    const int kstart = 0;
    int nerror = 0;

    auto tmp1 = fields.get_tmp();
    auto tmp2 = fields.get_tmp();

    // Soil temperature
    char filename[256];
    std::sprintf(filename, "%s.%07d", "t_soil", itime);
    master.print_message("Loading \"%s\" ... ", filename);

    if (field3d_io.load_field3d(
                t_soil->fld.data(),
                tmp1->fld.data(), tmp2->fld.data(),
                filename, no_offset,
                kstart, ktot))
    {
        master.print_message("FAILED\n");
        ++nerror;
    }
    else
        master.print_message("OK\n");

    // Soil moisture
    std::sprintf(filename, "%s.%07d", "theta_soil", itime);
    master.print_message("Loading \"%s\" ... ", filename);

    if (field3d_io.load_field3d(
                theta_soil->fld.data(),
                tmp1->fld.data(), tmp2->fld.data(),
                filename, no_offset,
                kstart, ktot))
    {
        master.print_message("FAILED\n");
        ++nerror;
    }
    else
        master.print_message("OK\n");

    fields.release_tmp(tmp1);
    fields.release_tmp(tmp2);

    master.sum(&nerror, 1);

    if (nerror)
        throw std::runtime_error("Error loading soil fields");
}

template class Soil_enabled<double>;
template class Soil_enabled<float>;
