cmake_minimum_required(VERSION 3.6)
project(mlcpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES data.h data.cpp matrix.h matrix.cpp)
add_library(mlcpp ${SOURCE_FILES})