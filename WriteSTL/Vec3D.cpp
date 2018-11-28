//
// Created by Xiaoyun Liu on 11/27/18.
//

#include <tuple>
#include "Vec3D.h"

Vec3D getFacetNormal(tuple<Vec3D, Vec3D, Vec3D> tri) {
    Vec3D p1 = get<0>(tri);
    Vec3D p2 = get<1>(tri);
    Vec3D p3 = get<2>(tri);

    double a = ((p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y));
    double b = ((p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z));
    double c = ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
    return Vec3D(a, b, c);
}
