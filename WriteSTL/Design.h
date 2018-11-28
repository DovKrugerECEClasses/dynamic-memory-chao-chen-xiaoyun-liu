//
// Created by Xiaoyun Liu on 11/28/18.
//

#pragma once
#include <iostream>
#include <vector>

#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"

using namespace std;

class Design {
private:
    vector<Shape> shapes;
public:
    void add(Shape s) {shapes.push_back(s);}
    void write(string filepath);
};