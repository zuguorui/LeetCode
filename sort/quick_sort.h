#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_


#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>


template<typename T>
void quick_sort(T* src, int32_t l, int32_t r)
{
    if(l >= r)
    {
        return;
    }

    int32_t baseIndex = (l + r) / 2;
    T base = src[baseIndex];

    int32_t leftIndex = l;
    int32_t rightIndex = r;

    while(leftIndex < rightIndex)
    {
        while(src[leftIndex] < base && leftIndex < rightIndex)
        {
            leftIndex++;
        }

        while(src[rightIndex] >= base && leftIndex < rightIndex)
        {
            rightIndex--;
        }
        if(leftIndex < rightIndex)
        {
            T temp = src[leftIndex];
            src[leftIndex] = src[rightIndex];
            src[rightIndex] = temp;
        }
    }

    src[leftIndex] = base;

    quick_sort(src, l, leftIndex - 1);
    quick_sort(src, rightIndex + 1, r);
    
}

#endif