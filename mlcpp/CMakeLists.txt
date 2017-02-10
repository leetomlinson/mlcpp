cmake_minimum_required(VERSION 3.6)
project(mlcpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrix.h)
add_library(mlcpp ${SOURCE_FILES})