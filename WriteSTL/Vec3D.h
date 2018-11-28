//
// Created by Xiaoyun Liu on 11/28/18.
//
#pragma once
#include <iostream>

using namespace std;

class Vec3D {
private:
    double x, y, z;
public:
    Vec3D(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX() {return x;}
    double getY() {return y;}
    double getZ() {return z;}

    friend ostream& operator<<(ostream& out, Vec3D v) {
        return out << v.x << ' ' << v.y << ' ' << v.z;
    }
    friend Vec3D getFacetNormal(tuple<Vec3D, Vec3D, Vec3D> tri);
};