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
CMAKE_SOURCE_DIR = /Users/francis/CLionProjects/git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/francis/CLionProjects/git/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/git.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/git.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/git.dir/flags.make

CMakeFiles/git.dir/main.c.o: CMakeFiles/git.dir/flags.make
CMakeFiles/git.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/francis/CLionProjects/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/git.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/git.dir/main.c.o   -c /Users/francis/CLionProjects/git/main.c

CMakeFiles/git.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/git.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/francis/CLionProjects/git/main.c > CMakeFiles/git.dir/main.c.i

CMakeFiles/git.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/git.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/francis/CLionProjects/git/main.c -o CMakeFiles/git.dir/main.c.s

# Object files for target git
git_OBJECTS = \
"CMakeFiles/git.dir/main.c.o"

# External object files for target git
git_EXTERNAL_OBJECTS =

git: CMakeFiles/git.dir/main.c.o
git: CMakeFiles/git.dir/build.make
git: CMakeFiles/git.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/francis/CLionProjects/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable git"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/git.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/git.dir/build: git

.PHONY : CMakeFiles/git.dir/build

CMakeFiles/git.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/git.dir/cmake_clean.cmake
.PHONY : CMakeFiles/git.dir/clean

CMakeFiles/git.dir/depend:
	cd /Users/francis/CLionProjects/git/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/francis/CLionProjects/git /Users/francis/CLionProjects/git /Users/francis/CLionProjects/git/cmake-build-debug /Users/francis/CLionProjects/git/cmake-build-debug /Users/francis/CLionProjects/git/cmake-build-debug/CMakeFiles/git.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/git.dir/depend
