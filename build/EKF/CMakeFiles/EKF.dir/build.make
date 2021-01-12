# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/oem/LORIS/CubeSat-ADCS/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oem/LORIS/CubeSat-ADCS/build

# Include any dependencies generated for this target.
include EKF/CMakeFiles/EKF.dir/depend.make

# Include the progress variables for this target.
include EKF/CMakeFiles/EKF.dir/progress.make

# Include the compile flags for this target's objects.
include EKF/CMakeFiles/EKF.dir/flags.make

EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o: EKF/CMakeFiles/EKF.dir/flags.make
EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o: /home/oem/LORIS/CubeSat-ADCS/Source/EKF/Extended_Kalman_Filter_RW.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oem/LORIS/CubeSat-ADCS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o"
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && /usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o -c /home/oem/LORIS/CubeSat-ADCS/Source/EKF/Extended_Kalman_Filter_RW.cpp

EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.i"
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oem/LORIS/CubeSat-ADCS/Source/EKF/Extended_Kalman_Filter_RW.cpp > CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.i

EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.s"
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oem/LORIS/CubeSat-ADCS/Source/EKF/Extended_Kalman_Filter_RW.cpp -o CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.s

# Object files for target EKF
EKF_OBJECTS = \
"CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o"

# External object files for target EKF
EKF_EXTERNAL_OBJECTS =

EKF/libEKF.a: EKF/CMakeFiles/EKF.dir/Extended_Kalman_Filter_RW.cpp.o
EKF/libEKF.a: EKF/CMakeFiles/EKF.dir/build.make
EKF/libEKF.a: EKF/CMakeFiles/EKF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oem/LORIS/CubeSat-ADCS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libEKF.a"
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && $(CMAKE_COMMAND) -P CMakeFiles/EKF.dir/cmake_clean_target.cmake
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EKF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
EKF/CMakeFiles/EKF.dir/build: EKF/libEKF.a

.PHONY : EKF/CMakeFiles/EKF.dir/build

EKF/CMakeFiles/EKF.dir/clean:
	cd /home/oem/LORIS/CubeSat-ADCS/build/EKF && $(CMAKE_COMMAND) -P CMakeFiles/EKF.dir/cmake_clean.cmake
.PHONY : EKF/CMakeFiles/EKF.dir/clean

EKF/CMakeFiles/EKF.dir/depend:
	cd /home/oem/LORIS/CubeSat-ADCS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oem/LORIS/CubeSat-ADCS/Source /home/oem/LORIS/CubeSat-ADCS/Source/EKF /home/oem/LORIS/CubeSat-ADCS/build /home/oem/LORIS/CubeSat-ADCS/build/EKF /home/oem/LORIS/CubeSat-ADCS/build/EKF/CMakeFiles/EKF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : EKF/CMakeFiles/EKF.dir/depend

