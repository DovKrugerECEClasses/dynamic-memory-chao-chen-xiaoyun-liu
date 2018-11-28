//
// Created by Xiaoyun Liu on 11/28/18.
//
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

#include "Vec3D.h"

using namespace std;

class Shape {
private:
    Vec3D centre;
    vector<tuple<Vec3D, Vec3D, Vec3D>> triangles;
public:
    Shape() : centre(Vec3D(0, 0, 0)) {}
    Shape(double x, double y, double z) : centre(Vec3D(x, y, z)) {}

    void write(string filepath);
    Vec3D& getCentre() {return centre;}
    vector<tuple<Vec3D, Vec3D, Vec3D>>& getTriangles() {return triangles;}
};