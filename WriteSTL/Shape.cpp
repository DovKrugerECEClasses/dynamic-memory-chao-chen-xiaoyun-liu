//
// Created by Xiaoyun Liu on 11/25/18.
//

#include "Shape.h"

void Shape::write(string filepath) {
    ofstream out(filepath, ofstream::app);
    out << "solid OpenSCAD_Model" << endl;
    for(auto i = triangles.begin(); i != triangles.end(); i++) {
        Vec3D facetNormal = getFacetNormal(*i);
        out << ' ' << "facet normal " << facetNormal << endl;
        out << ' ' << ' ' << "outer loop" << endl;
        out << ' ' << ' ' << ' ' << "vertex " << get<0>(*i) << endl;
        out << ' ' << ' ' << ' ' << "vertex " << get<1>(*i) << endl;
        out << ' ' << ' ' << ' ' << "vertex " << get<2>(*i) << endl;
        out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
    }
    out << "endsolid OpenSCAD_Model" << endl;
    out.close();
}