/*
	Cube
	Cylinder
	Sphere (optional)

https://en.wikipedia.org/wiki/STL_(file_format)
	
 */
#include <iostream>

#include "Cube.h"
#include "Cylinder.h"
#include "Design.h"

using namespace std;

int main() {
	Design d;
	double s = 10;
	Cube c(s);
	c.translate(20, 20, 20); //move centre
	// rotate??
	cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
  	d.add(c);
	double r = 10, height  = 20;
	Cylinder cyl(r, height);
	d.add(cyl);
	d.write("test.stl");
}
