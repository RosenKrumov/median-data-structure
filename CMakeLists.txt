cmake_minimum_required(VERSION 3.16)
project(median)

set(CMAKE_CXX_STANDARD 14)

add_executable(median src/main.cpp
                      src/median_structure.cpp)