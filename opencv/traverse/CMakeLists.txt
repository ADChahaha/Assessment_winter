cmake_minimum_required(VERSION 3.15)
project(traverse)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(traverse traverse.cpp)
target_link_libraries(traverse ${OpenCV_LIBS})
