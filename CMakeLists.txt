cmake_minimum_required(VERSION 3.16)
project(median
        DESCRIPTION "A median data structure")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(tests)