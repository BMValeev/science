# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/sielf/Downloads/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sielf/Downloads/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sielf/cloud/science

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sielf/cloud/science/cmake-build-cross1

# Utility rule file for ComCppSrc_autogen.

# Include the progress variables for this target.
include QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/progress.make

QController/comcpp/src/CMakeFiles/ComCppSrc_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ComCppSrc"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src && /home/sielf/Downloads/clion-2019.3.4/bin/cmake/linux/bin/cmake -E cmake_autogen /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/AutogenInfo.cmake Cross1

ComCppSrc_autogen: QController/comcpp/src/CMakeFiles/ComCppSrc_autogen
ComCppSrc_autogen: QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/build.make

.PHONY : ComCppSrc_autogen

# Rule to build all files generated by this target.
QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/build: ComCppSrc_autogen

.PHONY : QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/build

QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/clean:
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src && $(CMAKE_COMMAND) -P CMakeFiles/ComCppSrc_autogen.dir/cmake_clean.cmake
.PHONY : QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/clean

QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/depend:
	cd /home/sielf/cloud/science/cmake-build-cross1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sielf/cloud/science /home/sielf/cloud/science/QController/comcpp/src /home/sielf/cloud/science/cmake-build-cross1 /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QController/comcpp/src/CMakeFiles/ComCppSrc_autogen.dir/depend

