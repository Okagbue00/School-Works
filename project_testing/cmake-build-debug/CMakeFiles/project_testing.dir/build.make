# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/francis/CLionProjects/project_testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/francis/CLionProjects/project_testing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_testing.dir/flags.make

CMakeFiles/project_testing.dir/hello.c.o: CMakeFiles/project_testing.dir/flags.make
CMakeFiles/project_testing.dir/hello.c.o: ../hello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/francis/CLionProjects/project_testing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project_testing.dir/hello.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_testing.dir/hello.c.o   -c /Users/francis/CLionProjects/project_testing/hello.c

CMakeFiles/project_testing.dir/hello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_testing.dir/hello.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/francis/CLionProjects/project_testing/hello.c > CMakeFiles/project_testing.dir/hello.c.i

CMakeFiles/project_testing.dir/hello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_testing.dir/hello.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/francis/CLionProjects/project_testing/hello.c -o CMakeFiles/project_testing.dir/hello.c.s

# Object files for target project_testing
project_testing_OBJECTS = \
"CMakeFiles/project_testing.dir/hello.c.o"

# External object files for target project_testing
project_testing_EXTERNAL_OBJECTS =

project_testing: CMakeFiles/project_testing.dir/hello.c.o
project_testing: CMakeFiles/project_testing.dir/build.make
project_testing: CMakeFiles/project_testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/francis/CLionProjects/project_testing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project_testing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_testing.dir/build: project_testing

.PHONY : CMakeFiles/project_testing.dir/build

CMakeFiles/project_testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_testing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_testing.dir/clean

CMakeFiles/project_testing.dir/depend:
	cd /Users/francis/CLionProjects/project_testing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/francis/CLionProjects/project_testing /Users/francis/CLionProjects/project_testing /Users/francis/CLionProjects/project_testing/cmake-build-debug /Users/francis/CLionProjects/project_testing/cmake-build-debug /Users/francis/CLionProjects/project_testing/cmake-build-debug/CMakeFiles/project_testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_testing.dir/depend
