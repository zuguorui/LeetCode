#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdint.h>

template<typename T>
void shell_sort(T *src, int32_t l, int32_t r)
{
    if(l >= r)
    {
        return;
    }
    int len = r - l;
    while(len >= 1)
    {
        int index = 0;
        while(len + index <= r)
        {
            if(src[index] > src[index + len])
            {
                T temp = src[index];
                src[index] = src[index + len];
                src[index + len] = temp;
            }
            index++;
        }
        len--;
    }

}

#endif