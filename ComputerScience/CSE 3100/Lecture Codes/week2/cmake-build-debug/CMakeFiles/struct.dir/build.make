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
CMAKE_SOURCE_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/struct.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/struct.dir/flags.make

CMakeFiles/struct.dir/struct.c.o: CMakeFiles/struct.dir/flags.make
CMakeFiles/struct.dir/struct.c.o: ../struct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/struct.dir/struct.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/struct.dir/struct.c.o -c "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/struct.c"

CMakeFiles/struct.dir/struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/struct.dir/struct.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/struct.c" > CMakeFiles/struct.dir/struct.c.i

CMakeFiles/struct.dir/struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/struct.dir/struct.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/struct.c" -o CMakeFiles/struct.dir/struct.c.s

# Object files for target struct
struct_OBJECTS = \
"CMakeFiles/struct.dir/struct.c.o"

# External object files for target struct
struct_EXTERNAL_OBJECTS =

struct: CMakeFiles/struct.dir/struct.c.o
struct: CMakeFiles/struct.dir/build.make
struct: CMakeFiles/struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable struct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/struct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/struct.dir/build: struct
.PHONY : CMakeFiles/struct.dir/build

CMakeFiles/struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/struct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/struct.dir/clean

CMakeFiles/struct.dir/depend:
	cd "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug" "/home/mastermind63/Documents/UCONN/Fall 2021/CSE3100/Lecture Codes/week2/cmake-build-debug/CMakeFiles/struct.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/struct.dir/depend

