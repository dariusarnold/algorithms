cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/extern/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif()
add_subdirectory(${GOOGLETEST_DIR})
include_directories(${GOOGLETEST_DIR}/googletest/include ${GOOGLETEST_DIR})

add_subdirectory(sorting)
