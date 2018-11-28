//
// Created by Xiaoyun Liu on 11/28/18.
//

#pragma once
#include <fstream>
#include <iostream>
#include <math.h>

#include "Shape.h"

using namespace std;

class Cylinder : public Shape {
private:
    double r, h, f;
public:
    Cylinder(double r, double h, double f = 10) : r(r), h(h), f(f) {init();}
    Cylinder(double x, double y, double z, double r, double h, double f = 10) :
        Shape(x, y, z), r(r), h(h), f(f) {
        init();
    }

    void init();
    void translate(double x, double y, double z);
    double volume() {return M_PI * h * r * r;}
};
