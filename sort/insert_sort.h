#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_

#include <stdlib.h>
#include <stdint.h>

template<typename T>
void insert_sort(T *src, int32_t l, int32_t r)
{
    if(l >= r)
    {
        return;
    }

    int index = l + 1;
    while(index <= r)
    {
        int a = index - 1;
        while(src[a + 1] < src[a] && a >= 0)
        {
            T temp = src[a + 1];
            src[a + 1] = src[a];
            src[a] = temp;
            a--;
        }
        index++;
    }
}

#endif