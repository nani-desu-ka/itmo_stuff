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
CMAKE_SOURCE_DIR = /home/just/itmo_stuff/programming/Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/just/itmo_stuff/programming/Chess

# Include any dependencies generated for this target.
include CMakeFiles/lab_08.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_08.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_08.dir/flags.make

CMakeFiles/lab_08.dir/src/main.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_08.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/main.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/main.cpp

CMakeFiles/lab_08.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/main.cpp > CMakeFiles/lab_08.dir/src/main.cpp.i

CMakeFiles/lab_08.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/main.cpp -o CMakeFiles/lab_08.dir/src/main.cpp.s

CMakeFiles/lab_08.dir/src/Board.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Board.cpp.o: src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab_08.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Board.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Board.cpp

CMakeFiles/lab_08.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Board.cpp > CMakeFiles/lab_08.dir/src/Board.cpp.i

CMakeFiles/lab_08.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Board.cpp -o CMakeFiles/lab_08.dir/src/Board.cpp.s

CMakeFiles/lab_08.dir/src/Element.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Element.cpp.o: src/Element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab_08.dir/src/Element.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Element.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Element.cpp

CMakeFiles/lab_08.dir/src/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Element.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Element.cpp > CMakeFiles/lab_08.dir/src/Element.cpp.i

CMakeFiles/lab_08.dir/src/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Element.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Element.cpp -o CMakeFiles/lab_08.dir/src/Element.cpp.s

CMakeFiles/lab_08.dir/src/Player.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Player.cpp.o: src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab_08.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Player.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Player.cpp

CMakeFiles/lab_08.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Player.cpp > CMakeFiles/lab_08.dir/src/Player.cpp.i

CMakeFiles/lab_08.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Player.cpp -o CMakeFiles/lab_08.dir/src/Player.cpp.s

CMakeFiles/lab_08.dir/src/Pawn.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Pawn.cpp.o: src/Pawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab_08.dir/src/Pawn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Pawn.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Pawn.cpp

CMakeFiles/lab_08.dir/src/Pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Pawn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Pawn.cpp > CMakeFiles/lab_08.dir/src/Pawn.cpp.i

CMakeFiles/lab_08.dir/src/Pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Pawn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Pawn.cpp -o CMakeFiles/lab_08.dir/src/Pawn.cpp.s

CMakeFiles/lab_08.dir/src/Empty.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Empty.cpp.o: src/Empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab_08.dir/src/Empty.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Empty.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Empty.cpp

CMakeFiles/lab_08.dir/src/Empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Empty.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Empty.cpp > CMakeFiles/lab_08.dir/src/Empty.cpp.i

CMakeFiles/lab_08.dir/src/Empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Empty.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Empty.cpp -o CMakeFiles/lab_08.dir/src/Empty.cpp.s

CMakeFiles/lab_08.dir/src/Turn.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Turn.cpp.o: src/Turn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab_08.dir/src/Turn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Turn.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Turn.cpp

CMakeFiles/lab_08.dir/src/Turn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Turn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Turn.cpp > CMakeFiles/lab_08.dir/src/Turn.cpp.i

CMakeFiles/lab_08.dir/src/Turn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Turn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Turn.cpp -o CMakeFiles/lab_08.dir/src/Turn.cpp.s

CMakeFiles/lab_08.dir/src/Knight.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Knight.cpp.o: src/Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lab_08.dir/src/Knight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Knight.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Knight.cpp

CMakeFiles/lab_08.dir/src/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Knight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Knight.cpp > CMakeFiles/lab_08.dir/src/Knight.cpp.i

CMakeFiles/lab_08.dir/src/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Knight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Knight.cpp -o CMakeFiles/lab_08.dir/src/Knight.cpp.s

CMakeFiles/lab_08.dir/src/Bishop.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Bishop.cpp.o: src/Bishop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lab_08.dir/src/Bishop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Bishop.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Bishop.cpp

CMakeFiles/lab_08.dir/src/Bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Bishop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Bishop.cpp > CMakeFiles/lab_08.dir/src/Bishop.cpp.i

CMakeFiles/lab_08.dir/src/Bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Bishop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Bishop.cpp -o CMakeFiles/lab_08.dir/src/Bishop.cpp.s

CMakeFiles/lab_08.dir/src/Castle.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/src/Castle.cpp.o: src/Castle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/lab_08.dir/src/Castle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_08.dir/src/Castle.cpp.o -c /home/just/itmo_stuff/programming/Chess/src/Castle.cpp

CMakeFiles/lab_08.dir/src/Castle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/src/Castle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/just/itmo_stuff/programming/Chess/src/Castle.cpp > CMakeFiles/lab_08.dir/src/Castle.cpp.i

CMakeFiles/lab_08.dir/src/Castle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/src/Castle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/just/itmo_stuff/programming/Chess/src/Castle.cpp -o CMakeFiles/lab_08.dir/src/Castle.cpp.s

# Object files for target lab_08
lab_08_OBJECTS = \
"CMakeFiles/lab_08.dir/src/main.cpp.o" \
"CMakeFiles/lab_08.dir/src/Board.cpp.o" \
"CMakeFiles/lab_08.dir/src/Element.cpp.o" \
"CMakeFiles/lab_08.dir/src/Player.cpp.o" \
"CMakeFiles/lab_08.dir/src/Pawn.cpp.o" \
"CMakeFiles/lab_08.dir/src/Empty.cpp.o" \
"CMakeFiles/lab_08.dir/src/Turn.cpp.o" \
"CMakeFiles/lab_08.dir/src/Knight.cpp.o" \
"CMakeFiles/lab_08.dir/src/Bishop.cpp.o" \
"CMakeFiles/lab_08.dir/src/Castle.cpp.o"

# External object files for target lab_08
lab_08_EXTERNAL_OBJECTS =

lab_08: CMakeFiles/lab_08.dir/src/main.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Board.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Element.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Player.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Pawn.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Empty.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Turn.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Knight.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Bishop.cpp.o
lab_08: CMakeFiles/lab_08.dir/src/Castle.cpp.o
lab_08: CMakeFiles/lab_08.dir/build.make
lab_08: /usr/lib/x86_64-linux-gnu/libOpenGL.so
lab_08: /usr/lib/x86_64-linux-gnu/libGLX.so
lab_08: /usr/lib/x86_64-linux-gnu/libGLU.so
lab_08: /usr/lib/x86_64-linux-gnu/libglut.so
lab_08: CMakeFiles/lab_08.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/just/itmo_stuff/programming/Chess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable lab_08"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_08.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_08.dir/build: lab_08

.PHONY : CMakeFiles/lab_08.dir/build

CMakeFiles/lab_08.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_08.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_08.dir/clean

CMakeFiles/lab_08.dir/depend:
	cd /home/just/itmo_stuff/programming/Chess && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/just/itmo_stuff/programming/Chess /home/just/itmo_stuff/programming/Chess /home/just/itmo_stuff/programming/Chess /home/just/itmo_stuff/programming/Chess /home/just/itmo_stuff/programming/Chess/CMakeFiles/lab_08.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_08.dir/depend

