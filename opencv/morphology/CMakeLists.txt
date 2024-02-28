cmake_minimum_required(VERSION 3.15)
project(morphology)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(morphology morphology.cpp)
target_link_libraries(morphology ${OpenCV_LIBS})
