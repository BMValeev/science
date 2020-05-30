project(ComCppSrc)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDEDIR ${PKG_CONFIG_SYSROOT_DIR}${includedir})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOSTATICPLUGINS ON)
get_property(QT5_PATH GLOBAL PROPERTY QT5PATH)
if(NOT DEFINED ${CMAKE_PREFIX_PATH})
    set(CMAKE_PREFIX_PATH ${QT5_PATH})
endif()
set(Qt5_DIR  ${CMAKE_PREFIX_PATH}/Qt5)
find_library(PTHREAD_LIBRARY pthread)
find_package(PkgConfig REQUIRED )
find_package(Qt5 5.9 COMPONENTS  Qml Core REQUIRED)
add_definitions(${QtQml_DEFINITIONS})
list(APPEND LIBRARIES_COMCPPSRC
        ${PTHREAD_LIBRARY}
        SmartControl
        qio
        LineEd
        failure
        QtLog
        enumerables
        HardwareClasses
        Qt5::Core
        Qt5::Qml
        )
list(APPEND DIRECTORIES_COMCPPSRC
        ${CMAKE_CURRENT_SOURCE_DIR}
        "c_class"
        "enumerables"
        "qio"
        "qtlog"
        "smartcontrol"
        "failureHandling"
        "lineeditor"
    )
set(SOURCE_FILES_COMCPPSRC
        circularqvector.cpp
        mqtextstream.cpp
        persistent.cpp
        qqmlreadonlypropertymap.cpp
        utils.cpp
        baseConfig.cpp
        )
add_subdirectory(enumerables)
add_subdirectory(failureHandling)
add_subdirectory(qio)
add_subdirectory(c_class)
add_subdirectory(lineeditor)
add_subdirectory(smartcontrol)
add_subdirectory(qtlog)

add_library(${PROJECT_NAME}        ${SOURCE_FILES_COMCPPSRC}   )
include_directories(${DIRECTORIES_COMCPPSRC})
link_directories(${DIRECTORIES_COMCPPSRC})
target_link_libraries (${PROJECT_NAME}   ${LIBRARIES_COMCPPSRC}  )
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)



#target_include_directories(${PROJECT_NAME}         ${DIRECTORIES}        )