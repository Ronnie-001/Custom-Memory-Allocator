#ifndef CALLOC_H
#define CALLOC_H

#include <iostream>
#include "memBlock.h"

class cAlloc 
{
private:
    char* m_memPool;
    memBlock* m_header;

public:
    cAlloc(char* memPool);

    cAlloc(const cAlloc& calloc) = delete;

    template<typename T>
    void alloc(std::size_t size) {}

    void dealloc(void* ptr) {}

private:
    void buildFreeList(memBlock* head, char* memPool);

    void removeMemoryBlock(memBlock& block) {}

    void addMemoryBlock(std::size_t size) {}
};

#endif // !CALLOC_H
#define CALLOC_H
