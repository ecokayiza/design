# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eco/桌面/design

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eco/桌面/design/build

# Include any dependencies generated for this target.
include CMakeFiles/util.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/util.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/util.dir/flags.make

CMakeFiles/util.dir/util/functions.c.o: CMakeFiles/util.dir/flags.make
CMakeFiles/util.dir/util/functions.c.o: ../util/functions.c
CMakeFiles/util.dir/util/functions.c.o: CMakeFiles/util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eco/桌面/design/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/util.dir/util/functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/util.dir/util/functions.c.o -MF CMakeFiles/util.dir/util/functions.c.o.d -o CMakeFiles/util.dir/util/functions.c.o -c /home/eco/桌面/design/util/functions.c

CMakeFiles/util.dir/util/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/util.dir/util/functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eco/桌面/design/util/functions.c > CMakeFiles/util.dir/util/functions.c.i

CMakeFiles/util.dir/util/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/util.dir/util/functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eco/桌面/design/util/functions.c -o CMakeFiles/util.dir/util/functions.c.s

# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/util/functions.c.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

libutil.so: CMakeFiles/util.dir/util/functions.c.o
libutil.so: CMakeFiles/util.dir/build.make
libutil.so: CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eco/桌面/design/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libutil.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/util.dir/build: libutil.so
.PHONY : CMakeFiles/util.dir/build

CMakeFiles/util.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : CMakeFiles/util.dir/clean

CMakeFiles/util.dir/depend:
	cd /home/eco/桌面/design/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eco/桌面/design /home/eco/桌面/design /home/eco/桌面/design/build /home/eco/桌面/design/build /home/eco/桌面/design/build/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/util.dir/depend

