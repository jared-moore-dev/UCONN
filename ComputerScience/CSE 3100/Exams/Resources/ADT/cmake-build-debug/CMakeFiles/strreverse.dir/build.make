# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/mastermind63/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mastermind63/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/strreverse.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/strreverse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strreverse.dir/flags.make

CMakeFiles/strreverse.dir/strreverse.c.o: CMakeFiles/strreverse.dir/flags.make
CMakeFiles/strreverse.dir/strreverse.c.o: ../strreverse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/strreverse.dir/strreverse.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strreverse.dir/strreverse.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/strreverse.c"

CMakeFiles/strreverse.dir/strreverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strreverse.dir/strreverse.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/strreverse.c" > CMakeFiles/strreverse.dir/strreverse.c.i

CMakeFiles/strreverse.dir/strreverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strreverse.dir/strreverse.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/strreverse.c" -o CMakeFiles/strreverse.dir/strreverse.c.s

# Object files for target strreverse
strreverse_OBJECTS = \
"CMakeFiles/strreverse.dir/strreverse.c.o"

# External object files for target strreverse
strreverse_EXTERNAL_OBJECTS =

strreverse: CMakeFiles/strreverse.dir/strreverse.c.o
strreverse: CMakeFiles/strreverse.dir/build.make
strreverse: CMakeFiles/strreverse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable strreverse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strreverse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strreverse.dir/build: strreverse
.PHONY : CMakeFiles/strreverse.dir/build

CMakeFiles/strreverse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strreverse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strreverse.dir/clean

CMakeFiles/strreverse.dir/depend:
	cd "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles/strreverse.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/strreverse.dir/depend

