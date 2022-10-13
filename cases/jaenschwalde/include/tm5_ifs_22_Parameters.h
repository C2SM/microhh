/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Parameter Header File                                            */
/*                                                                  */
/* Generated by KPP-2.2.3 symbolic chemistry Kinetics PreProcessor  */
/*       (http://www.cs.vt.edu/~asandu/Software/KPP)                */
/* KPP is distributed under GPL, the general public licence         */
/*       (http://www.gnu.org/copyleft/gpl.html)                     */
/* (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa           */
/* (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech            */
/*     With important contributions from:                           */
/*        M. Damian, Villanova University, USA                      */
/*        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany */
/*                                                                  */
/* File                 : tm5_ifs_22_Parameters.h                   */
/* Time                 : Wed Oct 12 11:08:37 2022                  */
/* Working directory    : /home/WUR/krol005/kpp/examples            */
/* Equation file        : tm5_ifs_22.kpp                            */
/* Output root filename : tm5_ifs_22                                */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                17          /* Number of chemical species */
#define NVAR                 14          /* Number of Variable species */
#define NVARACT              14          /* Number of Active species */
#define NFIX                 3           /* Number of Fixed species */
#define NREACT               46          /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               14          /* Starting of fixed in conc. vect. */
#define NONZERO              97          /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           101         /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                15          /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                47          /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                82          /* Length of Sparse Hessian */
#define NLOOKAT              17          /* Number of species to look at */
#define NMONITOR             3           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_H2O2             0          
#define ind_N2O5             1          
#define ind_CO               2          
#define ind_HNO3             3          
#define ind_ROOH             4          
#define ind_RH               5          
#define ind_HCHO             6          
#define ind_NO2              7          
#define ind_O3               8          
#define ind_OH               9          
#define ind_HO2              10         
#define ind_NO3              11         
#define ind_RO2              12         
#define ind_NO               13         

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_CH4              14         
#define ind_M                15         
#define ind_DUMMY            16         

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_CH4             0          
#define indf_M               1          
#define indf_DUMMY           2          

#define NJVRP                67          /* Length of sparse Jacobian JVRP */

#define NSTOICM              124         /* Length of Sparse Stoichiometric Matrix */
