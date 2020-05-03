#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <stdlib.h>
#include <stdint.h>
#include <memory.h>


// template<typename T>
// void merge_sort(T *src, int32_t l, int32_t r)
// {
//     if(l >= r)
//     {
//         return;
//     }

//     if(l + 1 == r)
//     {
//         if(src[l] > src[r])
//         {
//             T temp = src[l];
//             src[l] = src[r];
//             src[r] = temp;
//             return;
//         }
//     }else
//     {
//         int mid = (l + r) / 2;
//         merge_sort(src, l, mid);
//         merge_sort(src, mid + 1, r);

//         int leftIndex = l, rightIndex = mid + 1;
//         int len = r - l + 1;
//         T tempArray[len];
//         for(int i = 0; i < len; i++)
//         {
//             if(leftIndex > mid)
//             {
//                 tempArray[i] = src[rightIndex++];
//             }
//             else if(rightIndex > r)
//             {
//                 tempArray[i] = src[leftIndex++];
//             }
//             else
//             {
//                 if(src[leftIndex] < src[rightIndex])
//                 {
//                     tempArray[i] = src[leftIndex++];
//                 }else
//                 {
//                     tempArray[i] = src[rightIndex++];
//                 }
                
//             }
            
//         }

//         memcpy(src + l, tempArray, len * sizeof(T));

//     }
    
// }

template<typename T>
void merge_sort(T *src, int32_t l, int32_t r)
{
    if(l >= r)
    {
        return;
    }
    int len = r - l + 1;

    
    
    int sortCount = 0;

    T *tempArray = (int *)malloc(len * sizeof(T));

    int dis = 1;

    while(dis <= len)
    {
        int mergeStart = l;
        int tempIndex = 0;
        while(mergeStart < r)
        {
            int leftIndex = mergeStart;
            int rightIndex = leftIndex + dis;
            while(tempIndex < len)
            {
                if(leftIndex >= mergeStart + dis && rightIndex >= mergeStart + 2 * dis)
                {
                    break;
                }
                else if(leftIndex < mergeStart + dis && rightIndex < mergeStart + 2 * dis)
                {
                    if(src[leftIndex] < src[rightIndex])
                    {
                        tempArray[tempIndex++] = src[leftIndex++];
                    }else
                    {
                        tempArray[tempIndex++] = src[rightIndex++];
                    }
                    
                }
                else if(leftIndex >= mergeStart + dis)
                {
                    tempArray[tempIndex++] = src[rightIndex++];
                }
                else
                {
                    tempArray[tempIndex++] = src[leftIndex++];
                }
                
            }
            mergeStart += 2 * dis;
        }
        memcpy(src + l, tempArray, len * sizeof(T));
        dis *= 2;

    }

    free(tempArray);
}

#endif