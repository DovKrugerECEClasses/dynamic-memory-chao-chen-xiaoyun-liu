//
// Created by Xiaoyun Liu on 11/25/18.
//

#include "Design.h"

void Design::write(string filepath) {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i].write(filepath);
    }
}