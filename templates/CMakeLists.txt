cmake_minimum_required(VERSION 3.12)
project(templates)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(templatelist)

add_executable(templates
        templatelist/GrowArray.hh
        templatelist/TestGrowArray.cc
#        templatefunctions.cc
#        TestVec3d.cc
#        Vec3d.hh
        )
