//
// Created by Xiaoyun Liu on 11/25/18.
//

#include "Cylinder.h"

void Cylinder::init() {

    Vec3D centre = getCentre();
    double x = centre.getX();
    double y = centre.getY();
    double z = centre.getZ();

    vector<Vec3D> vertexes;

    for(int i = 0; i <= f; i++) {
        vertexes.push_back(Vec3D(x + r * cos(2 * M_PI / f * (i)), y + r * sin(2 * M_PI / f * (i)), h / 2 + z));
        vertexes.push_back(Vec3D(x + r * cos(2 * M_PI / f * (i)), y + r * sin(2 * M_PI / f * (i)), z - h / 2));
    }
    
    Vec3D vc_u(x, y, h/2 + z);
    Vec3D vc_d(x, y, z - h/2);
    vector<tuple<Vec3D, Vec3D, Vec3D>>& triangles = getTriangles();
    for(int i = 0; i+3 < vertexes.size() ; i += 2) {
        triangles.push_back(make_tuple(vertexes[i+1], vertexes[i+3], vertexes[i+2]));
        triangles.push_back(make_tuple(vertexes[i+2], vertexes[i], vertexes[i+1]));
        triangles.push_back(make_tuple(vertexes[i], vertexes[i+2], vc_u));
        triangles.push_back(make_tuple(vertexes[i+1], vc_d, vertexes[i+3]));
    }
}

void Cylinder::translate(double x, double y, double z) {
    Vec3D& centre = getCentre();
    centre = Vec3D(centre.getX() + x, centre.getY() + y, centre.getZ() + z);
    init();
}
