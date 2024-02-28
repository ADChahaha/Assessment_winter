cmake_minimum_required(VERSION 3.15)
project(BGR2HSV)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(BGR2HSV BGR2HSV.cpp)
target_link_libraries(BGR2HSV ${OpenCV_LIBS})
