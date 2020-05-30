cmake_minimum_required(VERSION 3.8)
project(HardwareClasses)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

list(APPEND LIBRARIES_C_CLASS
        SPIHardwareClasses
        RestHardwareClasses
        I2CHardwareClasses
        GpioHardwareClasses
        BacklightHardwareClasses
        SerialHardwareClasses
        )

#add_library(${PROJECT_NAME} ${SOURCE_FILES})
add_library(${PROJECT_NAME} )

#add_definitions(-DDEMO)
#include_directories(..)
list(APPEND DIRECTORIES_C_CLASS
        "Rest"
        "SPI"
        "I2C"
        "Backlight"
        "Serial"
        "Gpio"
        )
add_subdirectory(Rest)
add_subdirectory(SPI)
add_subdirectory(I2C)
add_subdirectory(Gpio)
add_subdirectory(Backlight)
add_subdirectory(Serial)

include_directories(${DIRECTORIES_C_CLASS})
link_directories(${DIRECTORIES_C_CLASS})


target_link_libraries (${PROJECT_NAME}
        ${LIBRARIES_C_CLASS}
        )
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)