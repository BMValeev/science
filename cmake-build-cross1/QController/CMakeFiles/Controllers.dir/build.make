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
include QController/CMakeFiles/Controllers.dir/depend.make

# Include the progress variables for this target.
include QController/CMakeFiles/Controllers.dir/progress.make

# Include the compile flags for this target's objects.
include QController/CMakeFiles/Controllers.dir/flags.make

QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o: QController/CMakeFiles/Controllers.dir/flags.make
QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o: QController/Controllers_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o -c /home/sielf/cloud/science/cmake-build-cross1/QController/Controllers_autogen/mocs_compilation.cpp

QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.i"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sielf/cloud/science/cmake-build-cross1/QController/Controllers_autogen/mocs_compilation.cpp > CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.i

QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.s"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sielf/cloud/science/cmake-build-cross1/QController/Controllers_autogen/mocs_compilation.cpp -o CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.s

QController/CMakeFiles/Controllers.dir/configSensor.cpp.o: QController/CMakeFiles/Controllers.dir/flags.make
QController/CMakeFiles/Controllers.dir/configSensor.cpp.o: ../QController/configSensor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object QController/CMakeFiles/Controllers.dir/configSensor.cpp.o"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controllers.dir/configSensor.cpp.o -c /home/sielf/cloud/science/QController/configSensor.cpp

QController/CMakeFiles/Controllers.dir/configSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controllers.dir/configSensor.cpp.i"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sielf/cloud/science/QController/configSensor.cpp > CMakeFiles/Controllers.dir/configSensor.cpp.i

QController/CMakeFiles/Controllers.dir/configSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controllers.dir/configSensor.cpp.s"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sielf/cloud/science/QController/configSensor.cpp -o CMakeFiles/Controllers.dir/configSensor.cpp.s

QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o: QController/CMakeFiles/Controllers.dir/flags.make
QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o: ../QController/QEnumerableMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o -c /home/sielf/cloud/science/QController/QEnumerableMap.cpp

QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controllers.dir/QEnumerableMap.cpp.i"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sielf/cloud/science/QController/QEnumerableMap.cpp > CMakeFiles/Controllers.dir/QEnumerableMap.cpp.i

QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controllers.dir/QEnumerableMap.cpp.s"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-g++ --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9hf-neon-oe-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sielf/cloud/science/QController/QEnumerableMap.cpp -o CMakeFiles/Controllers.dir/QEnumerableMap.cpp.s

# Object files for target Controllers
Controllers_OBJECTS = \
"CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Controllers.dir/configSensor.cpp.o" \
"CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o"

# External object files for target Controllers
Controllers_EXTERNAL_OBJECTS =

QController/libControllers.a: QController/CMakeFiles/Controllers.dir/Controllers_autogen/mocs_compilation.cpp.o
QController/libControllers.a: QController/CMakeFiles/Controllers.dir/configSensor.cpp.o
QController/libControllers.a: QController/CMakeFiles/Controllers.dir/QEnumerableMap.cpp.o
QController/libControllers.a: QController/CMakeFiles/Controllers.dir/build.make
QController/libControllers.a: QController/CMakeFiles/Controllers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sielf/cloud/science/cmake-build-cross1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libControllers.a"
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && $(CMAKE_COMMAND) -P CMakeFiles/Controllers.dir/cmake_clean_target.cmake
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Controllers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
QController/CMakeFiles/Controllers.dir/build: QController/libControllers.a

.PHONY : QController/CMakeFiles/Controllers.dir/build

QController/CMakeFiles/Controllers.dir/clean:
	cd /home/sielf/cloud/science/cmake-build-cross1/QController && $(CMAKE_COMMAND) -P CMakeFiles/Controllers.dir/cmake_clean.cmake
.PHONY : QController/CMakeFiles/Controllers.dir/clean

QController/CMakeFiles/Controllers.dir/depend:
	cd /home/sielf/cloud/science/cmake-build-cross1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sielf/cloud/science /home/sielf/cloud/science/QController /home/sielf/cloud/science/cmake-build-cross1 /home/sielf/cloud/science/cmake-build-cross1/QController /home/sielf/cloud/science/cmake-build-cross1/QController/CMakeFiles/Controllers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QController/CMakeFiles/Controllers.dir/depend

