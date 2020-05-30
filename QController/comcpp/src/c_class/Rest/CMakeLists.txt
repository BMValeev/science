cmake_minimum_required(VERSION 3.8)
project(RestHardwareClasses)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES_C_CLASS_REST
        crc.cpp
        loggable.cpp
        defs.cpp
        FlashCard.cpp
        DateModule.cpp
        )
add_library(${PROJECT_NAME} ${SOURCE_FILES_C_CLASS_REST})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME})