cmake_minimum_required(VERSION 3.15)
project(gama)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(gama gama.cpp)
target_link_libraries(gama ${OpenCV_LIBS})
