cmake_minimum_required(VERSION 3.8)
project(I2CHardwareClasses)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES_C_CLASS_I2C
        I2C.cpp
        ConnModule.cpp
        I2C.cpp
        BoardModule.cpp
        i2cpacket.cpp
        stc3115_Driver.cpp
        #charge.cpp
        chargeinterface.cpp
        Fpga_fhd.cpp
        Board_FHD.cpp
        )
add_library(${PROJECT_NAME} ${SOURCE_FILES_C_CLASS_I2C})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME} PRIVATE RestHardwareClasses)