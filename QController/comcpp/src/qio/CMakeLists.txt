project(qio)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOSTATICPLUGINS ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDEDIR ${PKG_CONFIG_SYSROOT_DIR}${includedir})
get_property(QT5_PATH GLOBAL PROPERTY QT5PATH)
if(NOT DEFINED ${CMAKE_PREFIX_PATH})
    set(CMAKE_PREFIX_PATH ${QT5_PATH})
endif()
set(Qt5_DIR  ${CMAKE_PREFIX_PATH}/Qt5)
find_library(PTHREAD_LIBRARY pthread)
find_package(PkgConfig REQUIRED )
find_package(Qt5 5.9 COMPONENTS Qml Quick Core QuickControls2 Multimedia SerialPort  REQUIRED)
add_definitions(${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

list(APPEND LIBRARIES_QIO
        ${PTHREAD_LIBRARY}
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Core
        Qt5::SerialPort
        Qt5::Multimedia
        )
list(APPEND DIRECTORIES_QIO
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${QtQml_INCLUDE_DIRS}
    )
set(SOURCE_FILES_QIO
        qioabstract.cpp
        qiorequestresponse.cpp
        qiotransactionbase.cpp
        qserialsettings.cpp
        )

add_library(${PROJECT_NAME}        ${SOURCE_FILES_QIO}   )
include_directories(${DIRECTORIES_QIO})
link_directories(${DIRECTORIES_QIO})
target_link_libraries (${PROJECT_NAME}   ${LIBRARIES_QIO}  )
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)



#target_include_directories(${PROJECT_NAME}         ${DIRECTORIES}        )