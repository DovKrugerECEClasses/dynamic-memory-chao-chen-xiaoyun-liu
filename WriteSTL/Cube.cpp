//
// Created by Xiaoyun Liu on 11/25/18.
//

#include "Cube.h"

void Cube::init() {

    //get all vertexes, 8
    Vec3D centre = getCentre();
    double x = centre.getX();
    double y = centre.getY();
    double z = centre.getZ();
    
    vector<Vec3D> vertexes;
    vertexes.push_back(Vec3D(x - h/2, y - h/2, z - h/2));
    vertexes.push_back(Vec3D(x - h/2, y + h/2, z - h/2));
    vertexes.push_back(Vec3D(x + h/2, y + h/2, z - h/2));
    vertexes.push_back(Vec3D(x + h/2, y - h/2, z - h/2));
    vertexes.push_back(Vec3D(x - h/2, y - h/2, z + h/2));
    vertexes.push_back(Vec3D(x - h/2, y + h/2, z + h/2));
    vertexes.push_back(Vec3D(x + h/2, y + h/2, z + h/2));
    vertexes.push_back(Vec3D(x + h/2, y - h/2, z + h/2));

    //get all triangles, 12
    vector<tuple<Vec3D, Vec3D, Vec3D>>& triangles = getTriangles();
    triangles.push_back(make_tuple(vertexes[0], vertexes[1], vertexes[2]));
    triangles.push_back(make_tuple(vertexes[2], vertexes[3], vertexes[0]));
    triangles.push_back(make_tuple(vertexes[6], vertexes[5], vertexes[4]));
    triangles.push_back(make_tuple(vertexes[4], vertexes[7], vertexes[6]));
    triangles.push_back(make_tuple(vertexes[1], vertexes[5], vertexes[6]));
    triangles.push_back(make_tuple(vertexes[6], vertexes[2], vertexes[1]));
    triangles.push_back(make_tuple(vertexes[0], vertexes[3], vertexes[7]));
    triangles.push_back(make_tuple(vertexes[7], vertexes[4], vertexes[0]));
    triangles.push_back(make_tuple(vertexes[2], vertexes[6], vertexes[7]));
    triangles.push_back(make_tuple(vertexes[7], vertexes[3], vertexes[2]));
    triangles.push_back(make_tuple(vertexes[1], vertexes[0], vertexes[4]));
    triangles.push_back(make_tuple(vertexes[4], vertexes[5], vertexes[1]));
}

void Cube::translate(double x, double y, double z) {
    Vec3D& centre = getCentre();
    centre = Vec3D(centre.getX() + x, centre.getY() + y, centre.getZ() + z);
    init();
}
