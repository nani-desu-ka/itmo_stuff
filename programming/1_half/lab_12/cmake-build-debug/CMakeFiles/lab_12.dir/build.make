# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\lab_12.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\lab_12.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab_12.dir\flags.make

CMakeFiles\lab_12.dir\main.c.obj: CMakeFiles\lab_12.dir\flags.make
CMakeFiles\lab_12.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab_12.dir/main.c.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab_12.dir\main.c.obj /FdCMakeFiles\lab_12.dir\ /FS -c C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\main.c
<<

CMakeFiles\lab_12.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab_12.dir/main.c.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\lab_12.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\main.c
<<

CMakeFiles\lab_12.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab_12.dir/main.c.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab_12.dir\main.c.s /c C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\main.c
<<

# Object files for target lab_12
lab_12_OBJECTS = \
"CMakeFiles\lab_12.dir\main.c.obj"

# External object files for target lab_12
lab_12_EXTERNAL_OBJECTS =

lab_12.exe: CMakeFiles\lab_12.dir\main.c.obj
lab_12.exe: CMakeFiles\lab_12.dir\build.make
lab_12.exe: CMakeFiles\lab_12.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab_12.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab_12.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\lab_12.dir\objects1.rsp @<<
 /out:lab_12.exe /implib:lab_12.lib /pdb:C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug\lab_12.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab_12.dir\build: lab_12.exe

.PHONY : CMakeFiles\lab_12.dir\build

CMakeFiles\lab_12.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab_12.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab_12.dir\clean

CMakeFiles\lab_12.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12 C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12 C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug C:\Users\user\Documents\GitHub\itmo_stuff\programming\1_half\lab_12\cmake-build-debug\CMakeFiles\lab_12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\lab_12.dir\depend
