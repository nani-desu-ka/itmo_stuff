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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/just/itmo_stuff/programming/lab_07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/just/itmo_stuff/programming/lab_07/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab_07.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_07.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_07.dir/flags.make

CMakeFiles/lab_07.dir/src/main.cpp.o: CMakeFiles/lab_07.dir/flags.make
CMakeFiles/lab_07.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/lab_07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_07.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_07.dir/src/main.cpp.o -c /home/just/itmo_stuff/programming/lab_07/src/main.cpp

CMakeFiles/lab_07.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_07.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/lab_07/src/main.cpp > CMakeFiles/lab_07.dir/src/main.cpp.i

CMakeFiles/lab_07.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_07.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/lab_07/src/main.cpp -o CMakeFiles/lab_07.dir/src/main.cpp.s

CMakeFiles/lab_07.dir/src/console_handler.cpp.o: CMakeFiles/lab_07.dir/flags.make
CMakeFiles/lab_07.dir/src/console_handler.cpp.o: ../src/console_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/lab_07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab_07.dir/src/console_handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_07.dir/src/console_handler.cpp.o -c /home/just/itmo_stuff/programming/lab_07/src/console_handler.cpp

CMakeFiles/lab_07.dir/src/console_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_07.dir/src/console_handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/lab_07/src/console_handler.cpp > CMakeFiles/lab_07.dir/src/console_handler.cpp.i

CMakeFiles/lab_07.dir/src/console_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_07.dir/src/console_handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/lab_07/src/console_handler.cpp -o CMakeFiles/lab_07.dir/src/console_handler.cpp.s

CMakeFiles/lab_07.dir/src/exception.cpp.o: CMakeFiles/lab_07.dir/flags.make
CMakeFiles/lab_07.dir/src/exception.cpp.o: ../src/exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/lab_07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab_07.dir/src/exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_07.dir/src/exception.cpp.o -c /home/just/itmo_stuff/programming/lab_07/src/exception.cpp

CMakeFiles/lab_07.dir/src/exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_07.dir/src/exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/lab_07/src/exception.cpp > CMakeFiles/lab_07.dir/src/exception.cpp.i

CMakeFiles/lab_07.dir/src/exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_07.dir/src/exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/lab_07/src/exception.cpp -o CMakeFiles/lab_07.dir/src/exception.cpp.s

# Object files for target lab_07
lab_07_OBJECTS = \
"CMakeFiles/lab_07.dir/src/main.cpp.o" \
"CMakeFiles/lab_07.dir/src/console_handler.cpp.o" \
"CMakeFiles/lab_07.dir/src/exception.cpp.o"

# External object files for target lab_07
lab_07_EXTERNAL_OBJECTS =

lab_07: CMakeFiles/lab_07.dir/src/main.cpp.o
lab_07: CMakeFiles/lab_07.dir/src/console_handler.cpp.o
lab_07: CMakeFiles/lab_07.dir/src/exception.cpp.o
lab_07: CMakeFiles/lab_07.dir/build.make
lab_07: CMakeFiles/lab_07.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/just/itmo_stuff/programming/lab_07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lab_07"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_07.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_07.dir/build: lab_07

.PHONY : CMakeFiles/lab_07.dir/build

CMakeFiles/lab_07.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_07.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_07.dir/clean

CMakeFiles/lab_07.dir/depend:
	cd /home/just/itmo_stuff/programming/lab_07/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/just/itmo_stuff/programming/lab_07 /home/just/itmo_stuff/programming/lab_07 /home/just/itmo_stuff/programming/lab_07/cmake-build-debug /home/just/itmo_stuff/programming/lab_07/cmake-build-debug /home/just/itmo_stuff/programming/lab_07/cmake-build-debug/CMakeFiles/lab_07.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_07.dir/depend

