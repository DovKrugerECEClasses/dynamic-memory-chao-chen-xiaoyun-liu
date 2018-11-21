cmake_minimum_required(VERSION 3.12)
project(bitmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bitmap
        main.cc
        Color.cpp Color.h)
