cmake_minimum_required(VERSION 3.8)
project(GpioHardwareClasses)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES_C_CLASS_CPIO
        GPIO.cpp
        GPIOSysfs.cpp
        gpiointerface.cpp
        )
add_library(${PROJECT_NAME} ${SOURCE_FILES_C_CLASS_GPIO})


include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries (${PROJECT_NAME} PRIVATE RestHardwareClasses)