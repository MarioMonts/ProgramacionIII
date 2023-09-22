cmake_minimum_required(VERSION 3.26)
project(MM)

set(CMAKE_CXX_STANDARD 17)

add_executable(MM main.cpp
        FloatCell.cpp
        FloatCell.h)
