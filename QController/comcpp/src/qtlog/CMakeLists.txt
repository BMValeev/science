project(QtLog)
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
find_package(Qt5 5.9 COMPONENTS Qml Quick Core QuickControls2 Multimedia  REQUIRED)
add_definitions(${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES qtlog.qrc)
list(APPEND LIBRARIES_QTLOG
        ${PTHREAD_LIBRARY}
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Core
        Qt5::Multimedia
        )
list(APPEND DIRECTORIES_QTLOG
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${QtQml_INCLUDE_DIRS}
    )
set(SOURCE_FILES_QTLOG
        log.cpp
        logfilemodel.cpp
        logmodel.cpp
        logmodelbase.cpp
        logsortfiltermodel.cpp
        qloggable.cpp
        qloggableobject.cpp
        )

add_library(${PROJECT_NAME}  ${SOURCE_FILES_QTLOG})
include_directories(${DIRECTORIES_QTLOG})
link_directories(${DIRECTORIES_QTLOG})
target_link_libraries (${PROJECT_NAME}   ${LIBRARIES_QTLOG}  )
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)



#target_include_directories(${PROJECT_NAME}         ${DIRECTORIES}        )