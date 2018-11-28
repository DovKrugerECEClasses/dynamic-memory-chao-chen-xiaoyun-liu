cmake_minimum_required(VERSION 3.12)
project(bitmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WriteSTL
        Shape.cpp
        Cube.cpp Vec3D.cpp Cylinder.cpp Design.cpp
        hwShapes.cc
        Vec3D.h Shape.h Cube.h Cylinder.h Design.h)
