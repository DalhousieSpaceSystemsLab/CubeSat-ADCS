# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/james/Documents/CubeSat-ADCS/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/Documents/CubeSat-ADCS/build

# Include any dependencies generated for this target.
include IGRF12/CMakeFiles/IGRF12.dir/depend.make

# Include the progress variables for this target.
include IGRF12/CMakeFiles/IGRF12.dir/progress.make

# Include the compile flags for this target's objects.
include IGRF12/CMakeFiles/IGRF12.dir/flags.make

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o: IGRF12/CMakeFiles/IGRF12.dir/flags.make
IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o: /home/james/Documents/CubeSat-ADCS/Source/IGRF12/igrf12.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/Documents/CubeSat-ADCS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o"
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IGRF12.dir/igrf12.cpp.o -c /home/james/Documents/CubeSat-ADCS/Source/IGRF12/igrf12.cpp

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IGRF12.dir/igrf12.cpp.i"
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/Documents/CubeSat-ADCS/Source/IGRF12/igrf12.cpp > CMakeFiles/IGRF12.dir/igrf12.cpp.i

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IGRF12.dir/igrf12.cpp.s"
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/Documents/CubeSat-ADCS/Source/IGRF12/igrf12.cpp -o CMakeFiles/IGRF12.dir/igrf12.cpp.s

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.requires:

.PHONY : IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.requires

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.provides: IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.requires
	$(MAKE) -f IGRF12/CMakeFiles/IGRF12.dir/build.make IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.provides.build
.PHONY : IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.provides

IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.provides.build: IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o


# Object files for target IGRF12
IGRF12_OBJECTS = \
"CMakeFiles/IGRF12.dir/igrf12.cpp.o"

# External object files for target IGRF12
IGRF12_EXTERNAL_OBJECTS =

IGRF12/libIGRF12.a: IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o
IGRF12/libIGRF12.a: IGRF12/CMakeFiles/IGRF12.dir/build.make
IGRF12/libIGRF12.a: IGRF12/CMakeFiles/IGRF12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/Documents/CubeSat-ADCS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libIGRF12.a"
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && $(CMAKE_COMMAND) -P CMakeFiles/IGRF12.dir/cmake_clean_target.cmake
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IGRF12.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
IGRF12/CMakeFiles/IGRF12.dir/build: IGRF12/libIGRF12.a

.PHONY : IGRF12/CMakeFiles/IGRF12.dir/build

IGRF12/CMakeFiles/IGRF12.dir/requires: IGRF12/CMakeFiles/IGRF12.dir/igrf12.cpp.o.requires

.PHONY : IGRF12/CMakeFiles/IGRF12.dir/requires

IGRF12/CMakeFiles/IGRF12.dir/clean:
	cd /home/james/Documents/CubeSat-ADCS/build/IGRF12 && $(CMAKE_COMMAND) -P CMakeFiles/IGRF12.dir/cmake_clean.cmake
.PHONY : IGRF12/CMakeFiles/IGRF12.dir/clean

IGRF12/CMakeFiles/IGRF12.dir/depend:
	cd /home/james/Documents/CubeSat-ADCS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/Documents/CubeSat-ADCS/Source /home/james/Documents/CubeSat-ADCS/Source/IGRF12 /home/james/Documents/CubeSat-ADCS/build /home/james/Documents/CubeSat-ADCS/build/IGRF12 /home/james/Documents/CubeSat-ADCS/build/IGRF12/CMakeFiles/IGRF12.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : IGRF12/CMakeFiles/IGRF12.dir/depend

