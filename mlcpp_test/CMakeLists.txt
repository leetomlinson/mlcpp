cmake_minimum_required(VERSION 3.6)
project(mlcpp_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES test_matrix.cpp)
add_executable(mlcpp_test ${SOURCE_FILES})

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../mlcpp)

target_link_libraries(mlcpp_test gtest gtest_main)
target_link_libraries(mlcpp_test mlcpp)