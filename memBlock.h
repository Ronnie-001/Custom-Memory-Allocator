#ifndef MEMBLOCK_H
#define MEMBLOCK_H

#include <cstddef>
#include <iterator>
#include <ostream>
#include <random>

// Used to keep track of avaliable memory spaces within the free list
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

inline std::ostream& operator<<(std::ostream& out, const memBlock& block)
{
    out << "Block(prev: " << block.prev << ", ptr: " << block.ptr << ", next: " << block.next;
    return out; 
}


#endif // !MEMBLOCK_H
#define MEMBLOCK_H
