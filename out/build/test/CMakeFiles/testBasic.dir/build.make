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
CMAKE_SOURCE_DIR = /home/maximosn/linkedhashmap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maximosn/linkedhashmap/out/build

# Include any dependencies generated for this target.
include test/CMakeFiles/testBasic.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testBasic.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testBasic.dir/flags.make

test/CMakeFiles/testBasic.dir/testBasic.cc.o: test/CMakeFiles/testBasic.dir/flags.make
test/CMakeFiles/testBasic.dir/testBasic.cc.o: ../../test/testBasic.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maximosn/linkedhashmap/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/testBasic.dir/testBasic.cc.o"
	cd /home/maximosn/linkedhashmap/out/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBasic.dir/testBasic.cc.o -c /home/maximosn/linkedhashmap/test/testBasic.cc

test/CMakeFiles/testBasic.dir/testBasic.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBasic.dir/testBasic.cc.i"
	cd /home/maximosn/linkedhashmap/out/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maximosn/linkedhashmap/test/testBasic.cc > CMakeFiles/testBasic.dir/testBasic.cc.i

test/CMakeFiles/testBasic.dir/testBasic.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBasic.dir/testBasic.cc.s"
	cd /home/maximosn/linkedhashmap/out/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maximosn/linkedhashmap/test/testBasic.cc -o CMakeFiles/testBasic.dir/testBasic.cc.s

# Object files for target testBasic
testBasic_OBJECTS = \
"CMakeFiles/testBasic.dir/testBasic.cc.o"

# External object files for target testBasic
testBasic_EXTERNAL_OBJECTS =

test/testBasic: test/CMakeFiles/testBasic.dir/testBasic.cc.o
test/testBasic: test/CMakeFiles/testBasic.dir/build.make
test/testBasic: test/CMakeFiles/testBasic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maximosn/linkedhashmap/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testBasic"
	cd /home/maximosn/linkedhashmap/out/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testBasic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testBasic.dir/build: test/testBasic

.PHONY : test/CMakeFiles/testBasic.dir/build

test/CMakeFiles/testBasic.dir/clean:
	cd /home/maximosn/linkedhashmap/out/build/test && $(CMAKE_COMMAND) -P CMakeFiles/testBasic.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testBasic.dir/clean

test/CMakeFiles/testBasic.dir/depend:
	cd /home/maximosn/linkedhashmap/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maximosn/linkedhashmap /home/maximosn/linkedhashmap/test /home/maximosn/linkedhashmap/out/build /home/maximosn/linkedhashmap/out/build/test /home/maximosn/linkedhashmap/out/build/test/CMakeFiles/testBasic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testBasic.dir/depend
