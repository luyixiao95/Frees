//
// Created by Luyi Xiao on 10/12/22.
//

#include "Chunk.h"
#include <iostream>

std::string Chunk::toString() {
    std::string str = "";
    str += "Allocate start at " + std::to_string(startPoint) + " with size of " + std::to_string(getAllocateSize()) + "\n";
    return str;
}

