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

# Include any dependencies generated for this target.
include QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/depend.make

# Include the progress variables for this target.
include QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/progress.make

# Include the compile flags for this target's objects.
include QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/flags.make

QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o: QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/flags.make
QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o: QController/comcpp/src/c_class/HardwareClasses_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o -c /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class/HardwareClasses_autogen/mocs_compilation.cpp

QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.i"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class/HardwareClasses_autogen/mocs_compilation.cpp > CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.i

QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.s"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class/HardwareClasses_autogen/mocs_compilation.cpp -o CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.s

# Object files for target HardwareClasses
HardwareClasses_OBJECTS = \
"CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o"

# External object files for target HardwareClasses
HardwareClasses_EXTERNAL_OBJECTS =

QController/comcpp/src/c_class/libHardwareClasses.a: QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/HardwareClasses_autogen/mocs_compilation.cpp.o
QController/comcpp/src/c_class/libHardwareClasses.a: QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/build.make
QController/comcpp/src/c_class/libHardwareClasses.a: QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHardwareClasses.a"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && $(CMAKE_COMMAND) -P CMakeFiles/HardwareClasses.dir/cmake_clean_target.cmake
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HardwareClasses.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/build: QController/comcpp/src/c_class/libHardwareClasses.a

.PHONY : QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/build

QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/clean:
	cd /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class && $(CMAKE_COMMAND) -P CMakeFiles/HardwareClasses.dir/cmake_clean.cmake
.PHONY : QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/clean

QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/depend:
	cd /home/sielf/cloud/science/cmake-build-cross1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sielf/cloud/science /home/sielf/cloud/science/QController/comcpp/src/c_class /home/sielf/cloud/science/cmake-build-cross1 /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class /home/sielf/cloud/science/cmake-build-cross1/QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QController/comcpp/src/c_class/CMakeFiles/HardwareClasses.dir/depend

