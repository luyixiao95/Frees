//
// Created by Luyi Xiao on 10/12/22.
//

#ifndef FREES_HEAP_H
#define FREES_HEAP_H


#include "Chunk.h"
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    int heapSize;
    vector<Chunk> chunks;
    int FreeType;
    bool isCoalesce;
    bool freeWorst(int size);
    bool freeBest(int size);
    bool freeFirst(int size);
public:
    explicit Heap(int size);
    bool malloc(int size) ;
    bool free(int size);
    void changeFreeType(int type) {FreeType = type;};
    bool coalesce();
    std::string toString();

};


#endif //FREES_HEAP_H
