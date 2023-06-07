# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thijs/git/microhh-dev/microhh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thijs/git/microhh-dev/microhh/build_cpu_dp

# Include any dependencies generated for this target.
include main/CMakeFiles/microhh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include main/CMakeFiles/microhh.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/microhh.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/microhh.dir/flags.make

main/CMakeFiles/microhh.dir/microhh.cxx.o: main/CMakeFiles/microhh.dir/flags.make
main/CMakeFiles/microhh.dir/microhh.cxx.o: ../main/microhh.cxx
main/CMakeFiles/microhh.dir/microhh.cxx.o: main/CMakeFiles/microhh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijs/git/microhh-dev/microhh/build_cpu_dp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/microhh.dir/microhh.cxx.o"
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/microhh.dir/microhh.cxx.o -MF CMakeFiles/microhh.dir/microhh.cxx.o.d -o CMakeFiles/microhh.dir/microhh.cxx.o -c /home/thijs/git/microhh-dev/microhh/main/microhh.cxx

main/CMakeFiles/microhh.dir/microhh.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microhh.dir/microhh.cxx.i"
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijs/git/microhh-dev/microhh/main/microhh.cxx > CMakeFiles/microhh.dir/microhh.cxx.i

main/CMakeFiles/microhh.dir/microhh.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microhh.dir/microhh.cxx.s"
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijs/git/microhh-dev/microhh/main/microhh.cxx -o CMakeFiles/microhh.dir/microhh.cxx.s

# Object files for target microhh
microhh_OBJECTS = \
"CMakeFiles/microhh.dir/microhh.cxx.o"

# External object files for target microhh
microhh_EXTERNAL_OBJECTS =

microhh: main/CMakeFiles/microhh.dir/microhh.cxx.o
microhh: main/CMakeFiles/microhh.dir/build.make
microhh: src/libmicrohhc.a
microhh: rte-rrtmgp-cpp/src_kernels/librte_rrtmgp_kernels.a
microhh: rte-rrtmgp-cpp/src/librte_rrtmgp.a
microhh: /usr/lib/x86_64-linux-gnu/libfftw3.so
microhh: /usr/lib/x86_64-linux-gnu/libfftw3f.so
microhh: /usr/lib/x86_64-linux-gnu/libnetcdf_c++4.so
microhh: /usr/lib/x86_64-linux-gnu/libnetcdf.so
microhh: /usr/lib/x86_64-linux-gnu/libhdf5_serial_hl.so
microhh: /usr/lib/x86_64-linux-gnu/libhdf5_serial.so
microhh: rte-rrtmgp-cpp/src_kernels/librte_rrtmgp_kernels.a
microhh: main/CMakeFiles/microhh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thijs/git/microhh-dev/microhh/build_cpu_dp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../microhh"
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/microhh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/microhh.dir/build: microhh
.PHONY : main/CMakeFiles/microhh.dir/build

main/CMakeFiles/microhh.dir/clean:
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main && $(CMAKE_COMMAND) -P CMakeFiles/microhh.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/microhh.dir/clean

main/CMakeFiles/microhh.dir/depend:
	cd /home/thijs/git/microhh-dev/microhh/build_cpu_dp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thijs/git/microhh-dev/microhh /home/thijs/git/microhh-dev/microhh/main /home/thijs/git/microhh-dev/microhh/build_cpu_dp /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main /home/thijs/git/microhh-dev/microhh/build_cpu_dp/main/CMakeFiles/microhh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/microhh.dir/depend

