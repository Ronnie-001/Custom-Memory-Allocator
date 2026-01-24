#ifndef MEMBLOCK_H
#define MEMBLOCK_H

// Used to keep track of avaliable memory spaces within the free list
#include <cstddef>
struct memBlock 
{
    // include metadata.
    void* ptr;
    // "size" here represents the number of BYTES a memory block is.
    std::size_t size;
    bool isAllocated = false;    

    memBlock* next;
    memBlock* prev;

};

#endif // !MEMBLOCK_H
#define MEMBLOCK_H
