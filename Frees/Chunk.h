//
// Created by Luyi Xiao on 10/12/22.
//

#ifndef FREES_CHUNK_H
#define FREES_CHUNK_H


#include <string>

class Chunk {
private:
    int startPoint;
    int allocateSize;
public:
    explicit Chunk(int start, int size) {
        startPoint = start;
        allocateSize = size;
    };
    int getStartPoint() {return startPoint;}
    int getAllocateSize() {return allocateSize;}
    int getEndPoint() {return startPoint + allocateSize;}
    void changeAllocateSize(int size) {allocateSize = size; }
    void reduceAllocatedSize(int size) {allocateSize -= size;}
    std::string toString();
};



#endif //FREES_CHUNK_H
