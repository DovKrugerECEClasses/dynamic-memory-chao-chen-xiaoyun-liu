//
// Created by Xiaoyun Liu on 11/28/18.
//
#pragma once
#include <fstream>
#include <iostream>

#include "Shape.h"

using namespace std;

class Cube : public Shape {
private:
    double h;
public:
    Cube(double h) : h(h) {init();}
    Cube(double x, double y, double z, double h) : Shape(x, y, z), h(h) {init();}
    void init();
    void translate(double x, double y, double z);
    double volume() {return h * h * h;}
};