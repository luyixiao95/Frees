cmake_minimum_required(VERSION 3.23)
project(Frees)

set(CMAKE_CXX_STANDARD 17)

add_executable(Frees main.cpp Chunk.cpp Chunk.h Heap.cpp Heap.h)
