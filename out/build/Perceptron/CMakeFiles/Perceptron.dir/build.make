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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hurr1cane/Desktop/C++/LanguageDeterminer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build

# Include any dependencies generated for this target.
include Perceptron/CMakeFiles/Perceptron.dir/depend.make

# Include the progress variables for this target.
include Perceptron/CMakeFiles/Perceptron.dir/progress.make

# Include the compile flags for this target's objects.
include Perceptron/CMakeFiles/Perceptron.dir/flags.make

Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.o: Perceptron/CMakeFiles/Perceptron.dir/flags.make
Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.o: ../../Perceptron/Perceptron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.o"
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Perceptron.dir/Perceptron.cpp.o -c /home/hurr1cane/Desktop/C++/LanguageDeterminer/Perceptron/Perceptron.cpp

Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Perceptron.dir/Perceptron.cpp.i"
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hurr1cane/Desktop/C++/LanguageDeterminer/Perceptron/Perceptron.cpp > CMakeFiles/Perceptron.dir/Perceptron.cpp.i

Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Perceptron.dir/Perceptron.cpp.s"
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hurr1cane/Desktop/C++/LanguageDeterminer/Perceptron/Perceptron.cpp -o CMakeFiles/Perceptron.dir/Perceptron.cpp.s

# Object files for target Perceptron
Perceptron_OBJECTS = \
"CMakeFiles/Perceptron.dir/Perceptron.cpp.o"

# External object files for target Perceptron
Perceptron_EXTERNAL_OBJECTS =

Perceptron/libPerceptron.a: Perceptron/CMakeFiles/Perceptron.dir/Perceptron.cpp.o
Perceptron/libPerceptron.a: Perceptron/CMakeFiles/Perceptron.dir/build.make
Perceptron/libPerceptron.a: Perceptron/CMakeFiles/Perceptron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPerceptron.a"
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && $(CMAKE_COMMAND) -P CMakeFiles/Perceptron.dir/cmake_clean_target.cmake
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Perceptron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Perceptron/CMakeFiles/Perceptron.dir/build: Perceptron/libPerceptron.a

.PHONY : Perceptron/CMakeFiles/Perceptron.dir/build

Perceptron/CMakeFiles/Perceptron.dir/clean:
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron && $(CMAKE_COMMAND) -P CMakeFiles/Perceptron.dir/cmake_clean.cmake
.PHONY : Perceptron/CMakeFiles/Perceptron.dir/clean

Perceptron/CMakeFiles/Perceptron.dir/depend:
	cd /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hurr1cane/Desktop/C++/LanguageDeterminer /home/hurr1cane/Desktop/C++/LanguageDeterminer/Perceptron /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron /home/hurr1cane/Desktop/C++/LanguageDeterminer/out/build/Perceptron/CMakeFiles/Perceptron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Perceptron/CMakeFiles/Perceptron.dir/depend
