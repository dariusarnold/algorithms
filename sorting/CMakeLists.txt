cmake_minimum_required(VERSION 3.10)
project(sorting)

# Compiler/CMake settings
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_VERBOSE_MAKEFILE ON)

# Include googletest
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googletest)

# Include source files
add_subdirectory(src)

# main executable
add_executable(main src/main.cpp src/selectionSort.h src/bubbleSort.h)

# unit testing executable
add_executable(runUnitTests tests/testSortingAlgorithms.cpp)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)