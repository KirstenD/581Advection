# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kdawes/581Advection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kdawes/581Advection

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kdawes/581Advection/CMakeFiles /home/kdawes/581Advection/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kdawes/581Advection/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named advection

# Build rule for target.
advection: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 advection
.PHONY : advection

# fast build rule for target.
advection/fast:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/build
.PHONY : advection/fast

common/common.o: common/common.cxx.o
.PHONY : common/common.o

# target to build an object file
common/common.cxx.o:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/common.cxx.o
.PHONY : common/common.cxx.o

common/common.i: common/common.cxx.i
.PHONY : common/common.i

# target to preprocess a source file
common/common.cxx.i:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/common.cxx.i
.PHONY : common/common.cxx.i

common/common.s: common/common.cxx.s
.PHONY : common/common.s

# target to generate assembly for a file
common/common.cxx.s:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/common.cxx.s
.PHONY : common/common.cxx.s

common/vtkcommon.o: common/vtkcommon.cxx.o
.PHONY : common/vtkcommon.o

# target to build an object file
common/vtkcommon.cxx.o:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/vtkcommon.cxx.o
.PHONY : common/vtkcommon.cxx.o

common/vtkcommon.i: common/vtkcommon.cxx.i
.PHONY : common/vtkcommon.i

# target to preprocess a source file
common/vtkcommon.cxx.i:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/vtkcommon.cxx.i
.PHONY : common/vtkcommon.cxx.i

common/vtkcommon.s: common/vtkcommon.cxx.s
.PHONY : common/vtkcommon.s

# target to generate assembly for a file
common/vtkcommon.cxx.s:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/common/vtkcommon.cxx.s
.PHONY : common/vtkcommon.cxx.s

euler/euler.o: euler/euler.cxx.o
.PHONY : euler/euler.o

# target to build an object file
euler/euler.cxx.o:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/euler.cxx.o
.PHONY : euler/euler.cxx.o

euler/euler.i: euler/euler.cxx.i
.PHONY : euler/euler.i

# target to preprocess a source file
euler/euler.cxx.i:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/euler.cxx.i
.PHONY : euler/euler.cxx.i

euler/euler.s: euler/euler.cxx.s
.PHONY : euler/euler.s

# target to generate assembly for a file
euler/euler.cxx.s:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/euler.cxx.s
.PHONY : euler/euler.cxx.s

euler/main.o: euler/main.cxx.o
.PHONY : euler/main.o

# target to build an object file
euler/main.cxx.o:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/main.cxx.o
.PHONY : euler/main.cxx.o

euler/main.i: euler/main.cxx.i
.PHONY : euler/main.i

# target to preprocess a source file
euler/main.cxx.i:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/main.cxx.i
.PHONY : euler/main.cxx.i

euler/main.s: euler/main.cxx.s
.PHONY : euler/main.s

# target to generate assembly for a file
euler/main.cxx.s:
	$(MAKE) -f CMakeFiles/advection.dir/build.make CMakeFiles/advection.dir/euler/main.cxx.s
.PHONY : euler/main.cxx.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... advection"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... common/common.o"
	@echo "... common/common.i"
	@echo "... common/common.s"
	@echo "... common/vtkcommon.o"
	@echo "... common/vtkcommon.i"
	@echo "... common/vtkcommon.s"
	@echo "... euler/euler.o"
	@echo "... euler/euler.i"
	@echo "... euler/euler.s"
	@echo "... euler/main.o"
	@echo "... euler/main.i"
	@echo "... euler/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
