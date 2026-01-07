#include <cstddef>
#include "memBlock.h"

// The class that will be used for the allocator.
class cAlloc
{
// member variable(s)
private:
    char* m_memPool;
    // Used to keep reference to the head of the "free list" (Linked List)
    memBlock* header;

public:
    // constructor
    cAlloc(char& memPool) 
    : m_memPool(&memPool) {}

    /* Delete the copy constructor, we don't want extra pools of memory being
     * made, as this will take up more memory than needed.
    */
    cAlloc(const cAlloc& calloc) = delete;
    
    // Make it a template function so that memory can be allocated to the specified type.
    template<typename T> 
    void* alloc(std::size_t size) {}

    void dealloc(void* ptr) {} 

private:
    //  Function used to construct the free list. 
    memBlock* buildFreeList(char* memPool) {}
    
    // Function used to remove block from LL once all
    // the memory from that block has been allocated.
    void removeMemoryBlock(memBlock& block) {}

    // Mainly used in the case coalasing of memory has to happen.
    void addMemoryBlock(std::size_t) {}
};
