#ifndef MEMBLOCK_H
#define MEMBLOCK_H

struct memBlock 
{
    // include metadata.
    void* ptr;
    memBlock* next;

    bool flag;
    int size;
};

#endif // !MEMBLOCK_H
#define MEMBLOCK_H
