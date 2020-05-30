cmake_minimum_required(VERSION 3.8)
project(BacklightHardwareClasses)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES_C_CLASS_BACKLIGHT
        screenlight.cpp
        backlight_driver.cpp
        backlight_pwm.cpp
        backlightinterface.cpp
        )
add_library(${PROJECT_NAME} ${SOURCE_FILES_C_CLASS_BACKLIGHT})


include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries (${PROJECT_NAME} PRIVATE RestHardwareClasses)