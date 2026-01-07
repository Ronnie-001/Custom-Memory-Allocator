#include <iostream>
#include "cAlloc.h"

int main()
{
    int x = 4;

    char* memory = new char[25];
    int* intPtr = reinterpret_cast<int*>(memory);

    *intPtr = x;
    intPtr += 1;

    return 0;
}
