cmake_minimum_required(VERSION 3.16)
project(Graphics_Demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CONFIGURATION_TYPES DEBUG)
set(OpenCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenCV3/x64/vc17/lib)
find_package(OpenCV)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/Eigen3)

file(GLOB General_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        )
add_library(General SHARED
        ${General_SRC}
        )
target_link_libraries(General ${OpenCV_LIBRARIES})

add_executable(Demo main.cpp)
target_link_libraries(Demo General)
target_link_libraries(Demo ${OpenCV_LIBRARIES})

