cmake_minimum_required(VERSION 3.15)
project(VideoCapture)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(VideoCapture VideoCapture.cpp)
target_link_libraries(VideoCapture ${OpenCV_LIBS})
