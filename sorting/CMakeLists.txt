cmake_minimum_required(VERSION 3.10)
project(sorting)

# Compiler/CMake settings
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_VERBOSE_MAKEFILE ON)

# Include source files
include_directories(src)

# main executable
add_executable(sorting_main src/main.cpp)

# unit testing executable
add_executable(sorting_tests tests/testSortingAlgorithms.cpp)
target_link_libraries(sorting_tests gtest gtest_main)