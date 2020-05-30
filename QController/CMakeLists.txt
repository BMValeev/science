project(Controllers)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOSTATICPLUGINS ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDEDIR ${PKG_CONFIG_SYSROOT_DIR}${includedir})
set(REQUIRED_QT_VERSION 5.9.6)
get_property(QT5_PATH GLOBAL PROPERTY QT5PATH)
if(NOT DEFINED ${CMAKE_PREFIX_PATH})
    set(CMAKE_PREFIX_PATH ${QT5_PATH})
endif()
set(Qt5_DIR  ${CMAKE_PREFIX_PATH}/Qt5)
find_library(PTHREAD_LIBRARY pthread)
#find_library(GOBJECT_LIBRARY gobject-2.0)
find_package(PkgConfig REQUIRED )
#find_package(GTK3 REQUIRED )
#find_package(GStreamer REQUIRED )
find_package(Qt5 ${REQUIRED_QT_VERSION} COMPONENTS Qml Quick Core QuickControls2 Multimedia  REQUIRED)
add_definitions(${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

list(APPEND LIBRARIES_CONTROLLER
        ${PTHREAD_LIBRARY}
        #${GOBJECT_LIBRARY}
        #${GSTREAMER_LIBRARIES}
        #${GST_LIBRARIES}
        #${GTK3_LIBRARY_DIRS}
        #VideoFiles
        ComCpp
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Core
        Qt5::Multimedia
        )
list(APPEND DIRECTORIES_CONTROLLER
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/comcpp/src
        #${GSTREAMER_INCLUDE_DIRS}
        #${GST_INCLUDE_DIRS}
        #${GTK3_INCLUDE_DIRS}
        ${QtQml_INCLUDE_DIRS}
        "comcpp"
        )
set(SOURCE_FILES_CONTROLLER
        configSensor.cpp
        QEnumerableMap.cpp
        )

add_library(${PROJECT_NAME}        ${SOURCE_FILES_CONTROLLER}   )
add_subdirectory(comcpp)
include_directories(${DIRECTORIES_CONTROLLER})
link_directories(${DIRECTORIES_CONTROLLER})
target_link_libraries (${PROJECT_NAME}   ${LIBRARIES_CONTROLLER}  )
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)



#target_include_directories(${PROJECT_NAME}         ${DIRECTORIES}        )