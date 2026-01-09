#include <cstddef>
#include <iostream>
#include "memBlock.h"

// The class that will be used for the allocator.
class cAlloc
{
// member variable(s)
private:
    char* m_memPool;
    // Used to keep reference to the head of the "free list" (Linked List)
    memBlock* m_header;

public:
    // constructor
    cAlloc(char* memPool) 
    : m_memPool(memPool) 
    {
        // Build the free list upon memory pool creation
        buildFreeList(m_header, m_memPool);
    }

    /* Delete the copy constructor, we don't want extra pools of memory being
     * made, as this will take up more memory than needed.
    */
    cAlloc(const cAlloc& calloc) = delete;
    
    // Make it a template function so that memory can be allocated to the specified type.
    template<typename T> 
    void alloc(std::size_t size) {}

    void dealloc(void* ptr) {} 

private:
    //  Function used to construct the free list. 
    //  Returns a memBlock* to the head of the constructed free list.
    void buildFreeList(memBlock* head, char* memPool) 
    {
        memBlock* temp; 
        for (int i = 0; i < sizeof(&memPool); i+= 4) {
            if (i == 0) {
                head->ptr = static_cast<void*>(&memPool);
                temp = head; 
            } else {
                memBlock* newBlock;                
                newBlock->ptr = static_cast<void*>(&memPool[i]);
                temp->next = newBlock;
                temp = newBlock;

                std::cout << newBlock->ptr << "->";
            }
        }
    }
    
    // Function used to remove block from LL once all
    // the memory from that block has been allocated.
    void removeMemoryBlock(memBlock& block) {}

    // Mainly used in the case coalasing of memory has to happen.
    void addMemoryBlock(std::size_t size) {}
};
