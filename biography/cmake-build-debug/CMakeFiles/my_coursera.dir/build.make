# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/81/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/81/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liza/CLionProjects/my_coursera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liza/CLionProjects/my_coursera/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_coursera.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_coursera.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_coursera.dir/flags.make

CMakeFiles/my_coursera.dir/main.cpp.o: CMakeFiles/my_coursera.dir/flags.make
CMakeFiles/my_coursera.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/CLionProjects/my_coursera/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_coursera.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_coursera.dir/main.cpp.o -c /home/liza/CLionProjects/my_coursera/main.cpp

CMakeFiles/my_coursera.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_coursera.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liza/CLionProjects/my_coursera/main.cpp > CMakeFiles/my_coursera.dir/main.cpp.i

CMakeFiles/my_coursera.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_coursera.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liza/CLionProjects/my_coursera/main.cpp -o CMakeFiles/my_coursera.dir/main.cpp.s

# Object files for target my_coursera
my_coursera_OBJECTS = \
"CMakeFiles/my_coursera.dir/main.cpp.o"

# External object files for target my_coursera
my_coursera_EXTERNAL_OBJECTS =

my_coursera: CMakeFiles/my_coursera.dir/main.cpp.o
my_coursera: CMakeFiles/my_coursera.dir/build.make
my_coursera: CMakeFiles/my_coursera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liza/CLionProjects/my_coursera/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_coursera"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_coursera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_coursera.dir/build: my_coursera

.PHONY : CMakeFiles/my_coursera.dir/build

CMakeFiles/my_coursera.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_coursera.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_coursera.dir/clean

CMakeFiles/my_coursera.dir/depend:
	cd /home/liza/CLionProjects/my_coursera/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liza/CLionProjects/my_coursera /home/liza/CLionProjects/my_coursera /home/liza/CLionProjects/my_coursera/cmake-build-debug /home/liza/CLionProjects/my_coursera/cmake-build-debug /home/liza/CLionProjects/my_coursera/cmake-build-debug/CMakeFiles/my_coursera.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_coursera.dir/depend

