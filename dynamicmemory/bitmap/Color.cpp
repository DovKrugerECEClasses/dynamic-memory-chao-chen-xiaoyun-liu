//
// Created by chaochen on 11/20/18.
//

#include <Color.h>

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
    uint8_t alpha = 0x00;
    rgba = (r << 24) + (g << 16) + (b << 8) + alpha;
}

uint32_t Color::getColor() {
    return rgba;
}

