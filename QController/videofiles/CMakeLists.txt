project(VideoFiles)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
add_library (${PROJECT_NAME} STATIC
        VideoAppInterface.cpp
        VideoInterface.cpp
        VideoApp.cpp
        VideoRecord.cpp
        VideoShow.cpp
        Names.cpp
        VideoRecordTranslation.cpp
        VideoSnapshot.cpp
        )


find_library(PTHREAD_LIBRARY pthread)
find_library(GOBJECT_LIBRARY gobject-2.0)
find_package(GTK3 REQUIRED)
find_package(GStreamer REQUIRED)
include_directories( ${CMAKE_SOURCE_DIR} )

message("Include Gstreamer pipelines")

target_include_directories(${PROJECT_NAME} PRIVATE
        ${GSTREAMER_INCLUDE_DIRS}
#        ${GST_INCLUDE_DIRS}
#        ${GTK3_INCLUDE_DIRS}
        )
link_libraries(pthread)
target_link_libraries (${PROJECT_NAME}
        INTERFACE ${GOBJECT_LIBRARY}
        INTERFACE ${GSTREAMER_LIBRARIES}
        INTERFACE ${GST_LIBRARIES}
        INTERFACE ${GTK3_LIBRARY_DIRS}
        INTERFACE ${PTHREAD_LIBRARY}
        pthread
        )
