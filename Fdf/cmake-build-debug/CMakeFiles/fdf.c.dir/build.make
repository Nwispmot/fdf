# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /private/var/folders/zz/zyxvpxvq6csfxvn_n0000wgr00073y/T/AppTranslocation/68692EFD-2345-4919-8581-A3684F0D5467/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/zz/zyxvpxvq6csfxvn_n0000wgr00073y/T/AppTranslocation/68692EFD-2345-4919-8581-A3684F0D5467/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nwispmot/Desktop/Fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nwispmot/Desktop/Fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fdf.c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fdf.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fdf.c.dir/flags.make

CMakeFiles/fdf.c.dir/keys.c.o: CMakeFiles/fdf.c.dir/flags.make
CMakeFiles/fdf.c.dir/keys.c.o: ../keys.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwispmot/Desktop/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fdf.c.dir/keys.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf.c.dir/keys.c.o   -c /Users/nwispmot/Desktop/Fdf/keys.c

CMakeFiles/fdf.c.dir/keys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf.c.dir/keys.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nwispmot/Desktop/Fdf/keys.c > CMakeFiles/fdf.c.dir/keys.c.i

CMakeFiles/fdf.c.dir/keys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf.c.dir/keys.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nwispmot/Desktop/Fdf/keys.c -o CMakeFiles/fdf.c.dir/keys.c.s

# Object files for target fdf.c
fdf_c_OBJECTS = \
"CMakeFiles/fdf.c.dir/keys.c.o"

# External object files for target fdf.c
fdf_c_EXTERNAL_OBJECTS =

libfdf.c.a: CMakeFiles/fdf.c.dir/keys.c.o
libfdf.c.a: CMakeFiles/fdf.c.dir/build.make
libfdf.c.a: CMakeFiles/fdf.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nwispmot/Desktop/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libfdf.c.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fdf.c.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fdf.c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fdf.c.dir/build: libfdf.c.a

.PHONY : CMakeFiles/fdf.c.dir/build

CMakeFiles/fdf.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fdf.c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fdf.c.dir/clean

CMakeFiles/fdf.c.dir/depend:
	cd /Users/nwispmot/Desktop/Fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nwispmot/Desktop/Fdf /Users/nwispmot/Desktop/Fdf /Users/nwispmot/Desktop/Fdf/cmake-build-debug /Users/nwispmot/Desktop/Fdf/cmake-build-debug /Users/nwispmot/Desktop/Fdf/cmake-build-debug/CMakeFiles/fdf.c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fdf.c.dir/depend

