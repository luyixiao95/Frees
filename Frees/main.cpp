#include <iostream>
#include "Heap.h"

int main() {
    Heap physicalMemory = Heap(100);
    physicalMemory.malloc(5);
    physicalMemory.malloc(10);
    physicalMemory.malloc(15);
    physicalMemory.malloc(20);
    physicalMemory.malloc(13);
    std::cout << physicalMemory.toString();
    //freeType : 0 worst, 1 best, 2 first
    physicalMemory.changeFreeType(0);
    physicalMemory.free(7);
    std::cout << physicalMemory.toString();

    Heap physicalMemory2 = Heap(100);
    physicalMemory2.malloc(5);
    physicalMemory2.malloc(10);
    physicalMemory2.malloc(15);
    physicalMemory2.malloc(20);
    physicalMemory2.malloc(13);
    //freeType : 0 worst, 1 best, 2 first
    physicalMemory2.changeFreeType(1);
    physicalMemory2.free(7);
    std::cout << physicalMemory2.toString();

    Heap physicalMemory3 = Heap(100);
    physicalMemory3.malloc(5);
    physicalMemory3.malloc(10);
    physicalMemory3.malloc(15);
    physicalMemory3.malloc(20);
    physicalMemory3.malloc(13);
    //freeType : 0 worst, 1 best, 2 first
    physicalMemory3.changeFreeType(2);
    physicalMemory3.free(7);
    std::cout << physicalMemory3.toString();

    Heap physicalMemory4 = Heap(100);
    physicalMemory4.malloc(5);
    physicalMemory4.malloc(10);
    physicalMemory4.malloc(15);
    physicalMemory4.malloc(20);
    physicalMemory4.malloc(13);
    physicalMemory4.changeFreeType(2);
    physicalMemory4.free(7);
    physicalMemory4.free(16);
    std::cout << physicalMemory4.toString();
    std::cout << "After coalesce: \n";
    physicalMemory4.coalesce();
    std::cout << physicalMemory4.toString();
    return 0;
}
