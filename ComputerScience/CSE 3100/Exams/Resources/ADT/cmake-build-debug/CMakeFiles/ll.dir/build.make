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
include CMakeFiles/ll.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ll.dir/flags.make

CMakeFiles/ll.dir/linkedlist.c.o: CMakeFiles/ll.dir/flags.make
CMakeFiles/ll.dir/linkedlist.c.o: ../linkedlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ll.dir/linkedlist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ll.dir/linkedlist.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/linkedlist.c"

CMakeFiles/ll.dir/linkedlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ll.dir/linkedlist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/linkedlist.c" > CMakeFiles/ll.dir/linkedlist.c.i

CMakeFiles/ll.dir/linkedlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ll.dir/linkedlist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/linkedlist.c" -o CMakeFiles/ll.dir/linkedlist.c.s

# Object files for target ll
ll_OBJECTS = \
"CMakeFiles/ll.dir/linkedlist.c.o"

# External object files for target ll
ll_EXTERNAL_OBJECTS =

ll: CMakeFiles/ll.dir/linkedlist.c.o
ll: CMakeFiles/ll.dir/build.make
ll: CMakeFiles/ll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ll.dir/build: ll
.PHONY : CMakeFiles/ll.dir/build

CMakeFiles/ll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ll.dir/clean

CMakeFiles/ll.dir/depend:
	cd "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Exams/Resources/ADT/cmake-build-debug/CMakeFiles/ll.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ll.dir/depend

