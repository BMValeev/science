project(MenuCameraFHD)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#-fstrict-aliasing -pedantic-errors -pedantic
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOSTATICPLUGINS ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDEDIR ${PKG_CONFIG_SYSROOT_DIR}${includedir})
#add_definitions(-DQT_NO_KEYWORDS)
set(REQUIRED_QT_VERSION 5.9.6)
if(NOT DEFINED QT5PATH)
    define_property(GLOBAL PROPERTY QT5PATH BRIEF_DOCS "path to qt5" FULL_DOCS "path to qt5" )
    set_property(GLOBAL PROPERTY QT5PATH ~/Qt/5.9.9/gcc_64)
endif()
if(NOT DEFINED ${CMAKE_PREFIX_PATH})
    set(CMAKE_PREFIX_PATH ~/Qt/5.9.9/gcc_64)
endif()
set(Qt5_DIR  ${CMAKE_PREFIX_PATH}/Qt5)

find_library(PTHREAD_LIBRARY pthread)
find_package(PkgConfig REQUIRED )
find_package(Qt5 5.9 COMPONENTS Qml Quick Core Charts QuickControls2 Multimedia  REQUIRED)#Widgets
add_definitions(${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})#${QtWidgets_DEFINITIONS}
qt5_add_resources(QT_RESOURCES resources.qrc)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.45.0 COMPONENTS math)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()
add_subdirectory(QController)
list(APPEND LIBRARIES_FHD
        ${PTHREAD_LIBRARY}
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Core
        Qt5::Multimedia
        Qt5::Charts
        Controllers
        )
if(Boost_FOUND)
    list(APPEND LIBRARIES_FHD ${Boost_LIBRARIES})
endif()
list(APPEND DIRECTORIES_FHD
        ${QtQml_INCLUDE_DIRS}
        QController
        )
set(SOURCE_FILES_FHD
        main.cpp
        datasource.cpp
        sensordata.cpp
        )
include_directories( ${CMAKE_SOURCE_DIR}  ${DIRECTORIES_FHD} )#link_directories(${DIRECTORIES})
add_executable(${PROJECT_NAME}
        ${QT_RESOURCES}
        ${SOURCE_FILES_FHD}
        )

target_link_libraries (${PROJECT_NAME} PUBLIC  ${LIBRARIES_FHD}  )

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
