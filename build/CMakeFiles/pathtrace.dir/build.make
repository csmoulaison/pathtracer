# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/csmoulaison/repos/pathtracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmoulaison/repos/pathtracer/build

# Include any dependencies generated for this target.
include CMakeFiles/pathtrace.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pathtrace.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pathtrace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pathtrace.dir/flags.make

CMakeFiles/pathtrace.dir/src/camera.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/camera.c.o: /home/csmoulaison/repos/pathtracer/src/camera.c
CMakeFiles/pathtrace.dir/src/camera.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pathtrace.dir/src/camera.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/camera.c.o -MF CMakeFiles/pathtrace.dir/src/camera.c.o.d -o CMakeFiles/pathtrace.dir/src/camera.c.o -c /home/csmoulaison/repos/pathtracer/src/camera.c

CMakeFiles/pathtrace.dir/src/camera.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/camera.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/camera.c > CMakeFiles/pathtrace.dir/src/camera.c.i

CMakeFiles/pathtrace.dir/src/camera.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/camera.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/camera.c -o CMakeFiles/pathtrace.dir/src/camera.c.s

CMakeFiles/pathtrace.dir/src/main.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/main.c.o: /home/csmoulaison/repos/pathtracer/src/main.c
CMakeFiles/pathtrace.dir/src/main.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pathtrace.dir/src/main.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/main.c.o -MF CMakeFiles/pathtrace.dir/src/main.c.o.d -o CMakeFiles/pathtrace.dir/src/main.c.o -c /home/csmoulaison/repos/pathtracer/src/main.c

CMakeFiles/pathtrace.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/main.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/main.c > CMakeFiles/pathtrace.dir/src/main.c.i

CMakeFiles/pathtrace.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/main.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/main.c -o CMakeFiles/pathtrace.dir/src/main.c.s

CMakeFiles/pathtrace.dir/src/math_utils.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/math_utils.c.o: /home/csmoulaison/repos/pathtracer/src/math_utils.c
CMakeFiles/pathtrace.dir/src/math_utils.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pathtrace.dir/src/math_utils.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/math_utils.c.o -MF CMakeFiles/pathtrace.dir/src/math_utils.c.o.d -o CMakeFiles/pathtrace.dir/src/math_utils.c.o -c /home/csmoulaison/repos/pathtracer/src/math_utils.c

CMakeFiles/pathtrace.dir/src/math_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/math_utils.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/math_utils.c > CMakeFiles/pathtrace.dir/src/math_utils.c.i

CMakeFiles/pathtrace.dir/src/math_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/math_utils.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/math_utils.c -o CMakeFiles/pathtrace.dir/src/math_utils.c.s

CMakeFiles/pathtrace.dir/src/matrix_transform.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/matrix_transform.c.o: /home/csmoulaison/repos/pathtracer/src/matrix_transform.c
CMakeFiles/pathtrace.dir/src/matrix_transform.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pathtrace.dir/src/matrix_transform.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/matrix_transform.c.o -MF CMakeFiles/pathtrace.dir/src/matrix_transform.c.o.d -o CMakeFiles/pathtrace.dir/src/matrix_transform.c.o -c /home/csmoulaison/repos/pathtracer/src/matrix_transform.c

CMakeFiles/pathtrace.dir/src/matrix_transform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/matrix_transform.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/matrix_transform.c > CMakeFiles/pathtrace.dir/src/matrix_transform.c.i

CMakeFiles/pathtrace.dir/src/matrix_transform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/matrix_transform.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/matrix_transform.c -o CMakeFiles/pathtrace.dir/src/matrix_transform.c.s

CMakeFiles/pathtrace.dir/src/min.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/min.c.o: /home/csmoulaison/repos/pathtracer/src/min.c
CMakeFiles/pathtrace.dir/src/min.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/pathtrace.dir/src/min.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/min.c.o -MF CMakeFiles/pathtrace.dir/src/min.c.o.d -o CMakeFiles/pathtrace.dir/src/min.c.o -c /home/csmoulaison/repos/pathtracer/src/min.c

CMakeFiles/pathtrace.dir/src/min.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/min.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/min.c > CMakeFiles/pathtrace.dir/src/min.c.i

CMakeFiles/pathtrace.dir/src/min.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/min.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/min.c -o CMakeFiles/pathtrace.dir/src/min.c.s

CMakeFiles/pathtrace.dir/src/pathtracer.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/pathtracer.c.o: /home/csmoulaison/repos/pathtracer/src/pathtracer.c
CMakeFiles/pathtrace.dir/src/pathtracer.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/pathtrace.dir/src/pathtracer.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/pathtracer.c.o -MF CMakeFiles/pathtrace.dir/src/pathtracer.c.o.d -o CMakeFiles/pathtrace.dir/src/pathtracer.c.o -c /home/csmoulaison/repos/pathtracer/src/pathtracer.c

CMakeFiles/pathtrace.dir/src/pathtracer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/pathtracer.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/pathtracer.c > CMakeFiles/pathtrace.dir/src/pathtracer.c.i

CMakeFiles/pathtrace.dir/src/pathtracer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/pathtracer.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/pathtracer.c -o CMakeFiles/pathtrace.dir/src/pathtracer.c.s

CMakeFiles/pathtrace.dir/src/platform.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/platform.c.o: /home/csmoulaison/repos/pathtracer/src/platform.c
CMakeFiles/pathtrace.dir/src/platform.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/pathtrace.dir/src/platform.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/platform.c.o -MF CMakeFiles/pathtrace.dir/src/platform.c.o.d -o CMakeFiles/pathtrace.dir/src/platform.c.o -c /home/csmoulaison/repos/pathtracer/src/platform.c

CMakeFiles/pathtrace.dir/src/platform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/platform.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/platform.c > CMakeFiles/pathtrace.dir/src/platform.c.i

CMakeFiles/pathtrace.dir/src/platform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/platform.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/platform.c -o CMakeFiles/pathtrace.dir/src/platform.c.s

CMakeFiles/pathtrace.dir/src/quaternion.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/quaternion.c.o: /home/csmoulaison/repos/pathtracer/src/quaternion.c
CMakeFiles/pathtrace.dir/src/quaternion.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/pathtrace.dir/src/quaternion.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/quaternion.c.o -MF CMakeFiles/pathtrace.dir/src/quaternion.c.o.d -o CMakeFiles/pathtrace.dir/src/quaternion.c.o -c /home/csmoulaison/repos/pathtracer/src/quaternion.c

CMakeFiles/pathtrace.dir/src/quaternion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/quaternion.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/quaternion.c > CMakeFiles/pathtrace.dir/src/quaternion.c.i

CMakeFiles/pathtrace.dir/src/quaternion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/quaternion.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/quaternion.c -o CMakeFiles/pathtrace.dir/src/quaternion.c.s

CMakeFiles/pathtrace.dir/src/ray.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/ray.c.o: /home/csmoulaison/repos/pathtracer/src/ray.c
CMakeFiles/pathtrace.dir/src/ray.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/pathtrace.dir/src/ray.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/ray.c.o -MF CMakeFiles/pathtrace.dir/src/ray.c.o.d -o CMakeFiles/pathtrace.dir/src/ray.c.o -c /home/csmoulaison/repos/pathtracer/src/ray.c

CMakeFiles/pathtrace.dir/src/ray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/ray.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/ray.c > CMakeFiles/pathtrace.dir/src/ray.c.i

CMakeFiles/pathtrace.dir/src/ray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/ray.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/ray.c -o CMakeFiles/pathtrace.dir/src/ray.c.s

CMakeFiles/pathtrace.dir/src/vector.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/vector.c.o: /home/csmoulaison/repos/pathtracer/src/vector.c
CMakeFiles/pathtrace.dir/src/vector.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/pathtrace.dir/src/vector.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/vector.c.o -MF CMakeFiles/pathtrace.dir/src/vector.c.o.d -o CMakeFiles/pathtrace.dir/src/vector.c.o -c /home/csmoulaison/repos/pathtracer/src/vector.c

CMakeFiles/pathtrace.dir/src/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/vector.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/vector.c > CMakeFiles/pathtrace.dir/src/vector.c.i

CMakeFiles/pathtrace.dir/src/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/vector.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/vector.c -o CMakeFiles/pathtrace.dir/src/vector.c.s

CMakeFiles/pathtrace.dir/src/world.c.o: CMakeFiles/pathtrace.dir/flags.make
CMakeFiles/pathtrace.dir/src/world.c.o: /home/csmoulaison/repos/pathtracer/src/world.c
CMakeFiles/pathtrace.dir/src/world.c.o: CMakeFiles/pathtrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/pathtrace.dir/src/world.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pathtrace.dir/src/world.c.o -MF CMakeFiles/pathtrace.dir/src/world.c.o.d -o CMakeFiles/pathtrace.dir/src/world.c.o -c /home/csmoulaison/repos/pathtracer/src/world.c

CMakeFiles/pathtrace.dir/src/world.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pathtrace.dir/src/world.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/pathtracer/src/world.c > CMakeFiles/pathtrace.dir/src/world.c.i

CMakeFiles/pathtrace.dir/src/world.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pathtrace.dir/src/world.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/pathtracer/src/world.c -o CMakeFiles/pathtrace.dir/src/world.c.s

# Object files for target pathtrace
pathtrace_OBJECTS = \
"CMakeFiles/pathtrace.dir/src/camera.c.o" \
"CMakeFiles/pathtrace.dir/src/main.c.o" \
"CMakeFiles/pathtrace.dir/src/math_utils.c.o" \
"CMakeFiles/pathtrace.dir/src/matrix_transform.c.o" \
"CMakeFiles/pathtrace.dir/src/min.c.o" \
"CMakeFiles/pathtrace.dir/src/pathtracer.c.o" \
"CMakeFiles/pathtrace.dir/src/platform.c.o" \
"CMakeFiles/pathtrace.dir/src/quaternion.c.o" \
"CMakeFiles/pathtrace.dir/src/ray.c.o" \
"CMakeFiles/pathtrace.dir/src/vector.c.o" \
"CMakeFiles/pathtrace.dir/src/world.c.o"

# External object files for target pathtrace
pathtrace_EXTERNAL_OBJECTS =

pathtrace: CMakeFiles/pathtrace.dir/src/camera.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/main.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/math_utils.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/matrix_transform.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/min.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/pathtracer.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/platform.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/quaternion.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/ray.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/vector.c.o
pathtrace: CMakeFiles/pathtrace.dir/src/world.c.o
pathtrace: CMakeFiles/pathtrace.dir/build.make
pathtrace: /usr/lib/libSDL2main.a
pathtrace: /usr/lib/libSDL2-2.0.so.0.3000.4
pathtrace: CMakeFiles/pathtrace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/csmoulaison/repos/pathtracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable pathtrace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pathtrace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pathtrace.dir/build: pathtrace
.PHONY : CMakeFiles/pathtrace.dir/build

CMakeFiles/pathtrace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pathtrace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pathtrace.dir/clean

CMakeFiles/pathtrace.dir/depend:
	cd /home/csmoulaison/repos/pathtracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmoulaison/repos/pathtracer /home/csmoulaison/repos/pathtracer /home/csmoulaison/repos/pathtracer/build /home/csmoulaison/repos/pathtracer/build /home/csmoulaison/repos/pathtracer/build/CMakeFiles/pathtrace.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pathtrace.dir/depend

