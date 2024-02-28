cmake_minimum_required(VERSION 3.15)
project(count)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(count count.cpp)
target_link_libraries(count ${OpenCV_LIBS})
