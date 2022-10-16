//
// Created by Luyi Xiao on 10/12/22.
//

#include "Heap.h"

Heap::Heap(int size) {
    heapSize = size;
    FreeType =  0;
    isCoalesce = true;
}

bool Heap::malloc(int size) {
    if (size > heapSize) {
        return false;
    }

    if (chunks.empty()) {
        chunks.emplace_back(0, size);
        return true;
    }

    int lastTimeStamp = chunks.back().getEndPoint();
    if (lastTimeStamp + size >= heapSize) {
        return false;
    }
    chunks.emplace_back(lastTimeStamp, size);
    isCoalesce = false;
    return true;
}

bool Heap::free(int size) {

    if (FreeType == 0) {
        return freeWorst(size);
    }
    else if (FreeType == 1) {
        return freeBest(size);
    }
    else {
        return freeFirst(size);
    }
}

bool Heap::freeWorst(int size) {
    int worstSize = -1;
    int worstIdx = -1;
    int goThrough = 0 ;
    for(int i =0 ; i < chunks.size(); i++) {
        goThrough += 1;
        if (chunks[i].getAllocateSize() >= size && chunks[i].getAllocateSize() >= worstSize) {
            worstSize = chunks[i].getAllocateSize();
            worstIdx = i;
        }
    }
    if (worstIdx == -1) {
        return false;
    }
    std::cout << "Free succeeded: went through " + std::to_string(goThrough)  + " number of chunks, and free the size: "
    + std::to_string(worstSize) + "\n";

    chunks.erase(chunks.begin() + worstIdx);
    return true;
}

bool Heap::freeBest(int size) {
    int bestSize = heapSize;
    int bestIdx = -1;
    int goThrough = 0;
    for(int i =0 ; i < chunks.size(); i++) {
        goThrough += 1;
        if (chunks[i].getAllocateSize() >= size && chunks[i].getAllocateSize() < bestSize) {
            bestSize = chunks[i].getAllocateSize();
            bestIdx = i;
        }
    }
    if (bestIdx == -1) {
        return false;
    }
    chunks.erase(chunks.begin() + bestIdx);
    std::cout << "Free succeeded: went through " + std::to_string(goThrough)  + " number of chunks, and free the size: "
    + std::to_string(bestSize) + "\n";
    return true;
}

bool Heap::freeFirst(int size) {
    int goThrough = 0;
    for(int i =0 ; i < chunks.size(); i++) {
        goThrough += 1;
        if (chunks[i].getAllocateSize() >= size) {
            std::cout << "Free succeeded: went through " + std::to_string(goThrough)  + " number of chunks and free the size: "
            + std::to_string(chunks[i].getAllocateSize() ) + "\n";
            chunks.erase(chunks.begin() + i);
            return true;
        }
    }

    return false;
}

bool Heap::coalesce() {
    int totalSize = 0;
    for(Chunk &chunk : chunks) {
        totalSize += chunk.getAllocateSize();
    }
    chunks.clear();
    chunks.emplace_back(0, totalSize);
    isCoalesce = true;
    return true;
}

std::string Heap::toString() {

    std::string str = "";
    str += "Physical memory with memory of " + std::to_string(heapSize) + "\n";
    for (Chunk chunk: chunks){
        str += chunk.toString();
    }
    str += "\n";
    return str;
}





