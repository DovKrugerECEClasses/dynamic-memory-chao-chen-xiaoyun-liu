#include <iostream>
#include <algorithm>
#include <cmath>
#include "Color.h"

using namespace std;

class Bitmap {
private:
	uint32_t rows;
	uint32_t cols;
	char * map; // dynamic memory allocation

	char judgeColor(Color g) {
	    uint32_t res = g.getColor();
        switch(res) {
            case 0xffffff00: return 'W';
            case 0xff000000: return 'R';
            case 0x00ff0000: return 'G';
            case 0x0000ff00: return 'B';
            case 0x00000000: return 'K';

            default: return 'N';
        }
	}
	int floor(double x) {
		if(x - (int)x >= 0.5) return (int)x + 1;
		return (int)x;
	}

public:
    Bitmap(): rows(0), cols(0), map(new char[1]) {}
	Bitmap(uint32_t w, uint32_t l): rows(l), cols(w), map(new char[rows * cols]) {}
	~Bitmap() {
	    delete [] map;
	}
	// copy constructor
	Bitmap(const Bitmap& orig): rows(orig.rows), cols(orig.cols), map(new char[rows * cols]) {
	    for (uint32_t i = 0; i < rows * cols; ++i) {
	        map[i] = orig.map[i];
	    }
	}
	// assignment = operator
	Bitmap& operator = (const Bitmap& orig) {
	    Bitmap copy(orig);
	    rows = copy.rows;
	    cols = copy.cols;
	    swap(this->map, copy.map);
	    return *this;
	}
	void line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, Color r) {
        char c = judgeColor(r);

//  i = rowIndex * cols + colIndex
//	rowIndex: i / cols
//	colIndex: i % cols
		double k = (y1 - y0) / double(x1 - x0);
		double error = 0.0;
		uint32_t y = y0;
		for(uint32_t x = x0; x <= x1; ++x) {
			map[x + cols * y] = c;
			error = error + k;
			if (error >= 0.5) {
				y++;
				error -= 1.0;
			}
		}
	}
	void horizLine(uint32_t fromX, uint32_t toX, uint32_t y, Color g) {
		char c = judgeColor(g);
		for (uint32_t x = fromX; x <= toX; ++x) {
			map[y * cols + x] = c;
		}
	}
	void vertLine(uint32_t x, uint32_t fromY, uint32_t toY, Color g) {
		char c = judgeColor(g);
		for (uint32_t y = fromY; y <= toY; ++y) {
			map[y * cols + x] = c;
		}
	}
	void fillRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color b) {
		char c = judgeColor(b);
		for (uint32_t x0 = x; x0 < x + w - 1; ++x0) {
			for (uint32_t y0 = y; y0 < y + h - 1; ++y0) {
				map[y0 * cols + x0] = c;
			}
		}
	}
	void drawRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color c) {
		horizLine(x, x + w - 1, y, c);
		horizLine(x, x + w - 1, y + h - 1, c);
		vertLine(x, y, y + h - 1, c);
		vertLine(x + w - 1, y, y + h - 1, c);
	}
	void ellipse(uint32_t x0, uint32_t y0, uint32_t a, uint32_t b, Color r) {
		char c = judgeColor(r);

		a /= 2;
		b /= 2;

//		cout << "x0 is: " << x0 << "  y0 is: " << y0 << "  a is: " << a << "  b is: " << b << '\n';
//		cout << "the color is: " << c << '\n';
		for (int x = x0 - a; x <= x0 + a; ++x) {
		    for (int y = y0 - b; y <= int(y0 + b); ++y) {
		        double lefthandside = (x - x0) * (x - x0) / double(a * a) + (y - y0) * (y - y0) / double(b * b);
		        if (lefthandside <= 1) {
		            if (x + cols * y >= 0 && x + cols * y < cols * rows) {
                        map[x + cols * y] = c;
                    }
		        }
		    }
		}
	}

	friend ostream& operator << (ostream& c, const Bitmap& bitmap) {
		for (uint32_t i = 0; i < bitmap.rows; ++i) {
			for (uint32_t j = 0; j < bitmap.cols; ++j) {
				c << bitmap.map[i * bitmap.cols + j];
			}
			cout << '\n';
		}
		return c;
	}
};

int main() {
	Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
	// top left pixel = (0,0)
	Color RED(255,0,0); // all red, no green, no blue (fully opaque)
	Color BLUE(0,0,255);
	Color GREEN(0,255,0);
	Color WHITE(255,255,255);
	Color BLACK(0, 0, 0);

	b.line(0,0,19,19, RED);
	b.line(0,5,29,10, BLUE); //Bresenham algorithm
	//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

	// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	//TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
	b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
	b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
	b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3
	b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
  	b.ellipse(15, 0, 8, 5, RED);    // ellipse centered at (15,0) w = 8, h = 5
	cout << b;
	/*
R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB


	 */
}
