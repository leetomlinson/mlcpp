cmake_minimum_required(VERSION 3.6)
project(mlcpp_main)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(mlcpp_main ${SOURCE_FILES})

add_subdirectory(mlcpp)
add_subdirectory(mlcpp_test)

include_directories(mlcpp)

target_link_libraries(mlcpp_main mlcpp)