//
// Created by chaochen on 11/20/18.
//

#ifndef BITMAP_COLOR_H
#define BITMAP_COLOR_H

#include <cstdlib>

class Color {
private:
    uint32_t rgba;
public:
    Color(uint8_t r, uint8_t g, uint8_t b);
    //TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}
    uint32_t getColor();
};


#endif //BITMAP_COLOR_H
