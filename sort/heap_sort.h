#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "binary_heap.h"

template<typename T>
void heap_sort(T *src, int32_t l, int32_t r)
{
    if(l >= r)
    {
        return;
    }
    BinaryHeap<T> *heap = new BinaryHeap<T>(r - l + 1);
    for(int i = 0; i < r - l + 1; i++)
    {
        heap->push(src[i]);
    }

    for(int i = 0; i < r - l + 1; i++)
    {
        src[i] = heap->pop(INT32_MIN);
    }
        
    
    
}

#endif