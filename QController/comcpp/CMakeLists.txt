project(ComCpp)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
list(APPEND LIBRARIES_COMCPP
        ComCppSrc
        )

#add_library(${PROJECT_NAME} ${SOURCE_FILES})
add_library(${PROJECT_NAME} )

#add_definitions(-DDEMO)
#include_directories(..)
list(APPEND DIRECTORIES_COMCPP
        "src"
        )
add_subdirectory(src)
include_directories(${DIRECTORIES_COMCPP})
link_directories(${DIRECTORIES_COMCPP})
target_link_libraries (${PROJECT_NAME}
        ${LIBRARIES_COMCPP}
        )
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)