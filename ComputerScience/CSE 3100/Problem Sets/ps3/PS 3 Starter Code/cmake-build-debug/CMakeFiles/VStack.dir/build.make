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
CMAKE_SOURCE_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/VStack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/VStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VStack.dir/flags.make

CMakeFiles/VStack.dir/VStackTest.c.o: CMakeFiles/VStack.dir/flags.make
CMakeFiles/VStack.dir/VStackTest.c.o: ../VStackTest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/VStack.dir/VStackTest.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/VStack.dir/VStackTest.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStackTest.c"

CMakeFiles/VStack.dir/VStackTest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VStack.dir/VStackTest.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStackTest.c" > CMakeFiles/VStack.dir/VStackTest.c.i

CMakeFiles/VStack.dir/VStackTest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VStack.dir/VStackTest.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStackTest.c" -o CMakeFiles/VStack.dir/VStackTest.c.s

CMakeFiles/VStack.dir/vector.c.o: CMakeFiles/VStack.dir/flags.make
CMakeFiles/VStack.dir/vector.c.o: ../vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/VStack.dir/vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/VStack.dir/vector.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/vector.c"

CMakeFiles/VStack.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VStack.dir/vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/vector.c" > CMakeFiles/VStack.dir/vector.c.i

CMakeFiles/VStack.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VStack.dir/vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/vector.c" -o CMakeFiles/VStack.dir/vector.c.s

CMakeFiles/VStack.dir/VStack.c.o: CMakeFiles/VStack.dir/flags.make
CMakeFiles/VStack.dir/VStack.c.o: ../VStack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/VStack.dir/VStack.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/VStack.dir/VStack.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStack.c"

CMakeFiles/VStack.dir/VStack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VStack.dir/VStack.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStack.c" > CMakeFiles/VStack.dir/VStack.c.i

CMakeFiles/VStack.dir/VStack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VStack.dir/VStack.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/VStack.c" -o CMakeFiles/VStack.dir/VStack.c.s

# Object files for target VStack
VStack_OBJECTS = \
"CMakeFiles/VStack.dir/VStackTest.c.o" \
"CMakeFiles/VStack.dir/vector.c.o" \
"CMakeFiles/VStack.dir/VStack.c.o"

# External object files for target VStack
VStack_EXTERNAL_OBJECTS =

VStack: CMakeFiles/VStack.dir/VStackTest.c.o
VStack: CMakeFiles/VStack.dir/vector.c.o
VStack: CMakeFiles/VStack.dir/VStack.c.o
VStack: CMakeFiles/VStack.dir/build.make
VStack: CMakeFiles/VStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable VStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VStack.dir/build: VStack
.PHONY : CMakeFiles/VStack.dir/build

CMakeFiles/VStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VStack.dir/clean

CMakeFiles/VStack.dir/depend:
	cd "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Homework/ps3/PS 3 Starter Code/cmake-build-debug/CMakeFiles/VStack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/VStack.dir/depend

