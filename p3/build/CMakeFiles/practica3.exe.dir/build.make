# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gecoga98/Escritorio/4º/Algoritmica/p3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gecoga98/Escritorio/4º/Algoritmica/p3/build

# Include any dependencies generated for this target.
include CMakeFiles/practica3.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practica3.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practica3.exe.dir/flags.make

CMakeFiles/practica3.exe.dir/main.cpp.o: CMakeFiles/practica3.exe.dir/flags.make
CMakeFiles/practica3.exe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Escritorio/4º/Algoritmica/p3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practica3.exe.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica3.exe.dir/main.cpp.o -c /home/gecoga98/Escritorio/4º/Algoritmica/p3/main.cpp

CMakeFiles/practica3.exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica3.exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Escritorio/4º/Algoritmica/p3/main.cpp > CMakeFiles/practica3.exe.dir/main.cpp.i

CMakeFiles/practica3.exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica3.exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Escritorio/4º/Algoritmica/p3/main.cpp -o CMakeFiles/practica3.exe.dir/main.cpp.s

CMakeFiles/practica3.exe.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/practica3.exe.dir/main.cpp.o.requires

CMakeFiles/practica3.exe.dir/main.cpp.o.provides: CMakeFiles/practica3.exe.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica3.exe.dir/build.make CMakeFiles/practica3.exe.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/practica3.exe.dir/main.cpp.o.provides

CMakeFiles/practica3.exe.dir/main.cpp.o.provides.build: CMakeFiles/practica3.exe.dir/main.cpp.o


CMakeFiles/practica3.exe.dir/entero.cpp.o: CMakeFiles/practica3.exe.dir/flags.make
CMakeFiles/practica3.exe.dir/entero.cpp.o: ../entero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Escritorio/4º/Algoritmica/p3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/practica3.exe.dir/entero.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica3.exe.dir/entero.cpp.o -c /home/gecoga98/Escritorio/4º/Algoritmica/p3/entero.cpp

CMakeFiles/practica3.exe.dir/entero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica3.exe.dir/entero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Escritorio/4º/Algoritmica/p3/entero.cpp > CMakeFiles/practica3.exe.dir/entero.cpp.i

CMakeFiles/practica3.exe.dir/entero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica3.exe.dir/entero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Escritorio/4º/Algoritmica/p3/entero.cpp -o CMakeFiles/practica3.exe.dir/entero.cpp.s

CMakeFiles/practica3.exe.dir/entero.cpp.o.requires:

.PHONY : CMakeFiles/practica3.exe.dir/entero.cpp.o.requires

CMakeFiles/practica3.exe.dir/entero.cpp.o.provides: CMakeFiles/practica3.exe.dir/entero.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica3.exe.dir/build.make CMakeFiles/practica3.exe.dir/entero.cpp.o.provides.build
.PHONY : CMakeFiles/practica3.exe.dir/entero.cpp.o.provides

CMakeFiles/practica3.exe.dir/entero.cpp.o.provides.build: CMakeFiles/practica3.exe.dir/entero.cpp.o


# Object files for target practica3.exe
practica3_exe_OBJECTS = \
"CMakeFiles/practica3.exe.dir/main.cpp.o" \
"CMakeFiles/practica3.exe.dir/entero.cpp.o"

# External object files for target practica3.exe
practica3_exe_EXTERNAL_OBJECTS =

practica3.exe: CMakeFiles/practica3.exe.dir/main.cpp.o
practica3.exe: CMakeFiles/practica3.exe.dir/entero.cpp.o
practica3.exe: CMakeFiles/practica3.exe.dir/build.make
practica3.exe: CMakeFiles/practica3.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gecoga98/Escritorio/4º/Algoritmica/p3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable practica3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practica3.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practica3.exe.dir/build: practica3.exe

.PHONY : CMakeFiles/practica3.exe.dir/build

CMakeFiles/practica3.exe.dir/requires: CMakeFiles/practica3.exe.dir/main.cpp.o.requires
CMakeFiles/practica3.exe.dir/requires: CMakeFiles/practica3.exe.dir/entero.cpp.o.requires

.PHONY : CMakeFiles/practica3.exe.dir/requires

CMakeFiles/practica3.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practica3.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practica3.exe.dir/clean

CMakeFiles/practica3.exe.dir/depend:
	cd /home/gecoga98/Escritorio/4º/Algoritmica/p3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gecoga98/Escritorio/4º/Algoritmica/p3 /home/gecoga98/Escritorio/4º/Algoritmica/p3 /home/gecoga98/Escritorio/4º/Algoritmica/p3/build /home/gecoga98/Escritorio/4º/Algoritmica/p3/build /home/gecoga98/Escritorio/4º/Algoritmica/p3/build/CMakeFiles/practica3.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practica3.exe.dir/depend

