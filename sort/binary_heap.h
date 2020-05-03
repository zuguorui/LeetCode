#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <memory.h>

#include "util.h"

using namespace std;

template<typename T>
class BinaryHeap
{
public:
    BinaryHeap(int capacity = 100);
    ~BinaryHeap();
    void push(T t);
    T pop(T failValue);
    bool remove(T t);

    int size();

private:
    T *array = NULL;

    int mSize = 0;

    int capacity = 0;

    void checkHeap(int index);
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int capacity)
{
    array = (T *)malloc(capacity * sizeof(T));
    mSize = 0;
    this->capacity = capacity;
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    if(array)
    {
        free(array);
        array = NULL;
    }
}

template<typename T>
void BinaryHeap<T>::push(T t)
{
    if(mSize == capacity)
    {
        capacity = (int)(capacity * 1.2f);
        T *newArray = (T *)malloc(capacity * sizeof(T));
        memcpy(newArray, array, mSize * sizeof(T));
        free(array);
        array = newArray;
    }

    mSize += 1;
    int index = mSize - 1;
    array[index] = t;

    while(index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if(array[parentIndex] <= array[index])
        {
            break;
        }
        else
        {
            T temp = array[index];
            array[index] = array[parentIndex];
            array[parentIndex] = temp;
            index = parentIndex;
        }
        
    }

    // printf("after push one element: %d\n", (int)t);
    // checkHeap(0);
    // print_int_array((int *)array, mSize, 6);


}

template<typename T>
T BinaryHeap<T>::pop(T failValue)
{
    if(mSize == 0)
    {
        return failValue;
    }

    // printf("pop top\n");

    T root = array[0];

    remove(root);

    return root;
}

template<typename T>
bool BinaryHeap<T>::remove(T t)
{
    if(mSize == 0)
    {
        return false;
    }

    int index = -1;
    for(int i = 0; i < mSize; i++)
    {
        if(array[i] == t)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        return false;
    }

    // printf("remove element %d\n", (int)t);

    array[index] = array[mSize - 1];
    mSize -= 1;

    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    
    while(leftChildIndex < mSize)
    {
        
        if(rightChildIndex < mSize)
        {
            if(array[index] < array[leftChildIndex] && array[index] < array[rightChildIndex])
            {
                break;
            }
            else if(array[leftChildIndex] < array[rightChildIndex])
            {
                T temp = array[index];
                array[index] = array[leftChildIndex];
                array[leftChildIndex] = temp;
                index = leftChildIndex;
            }
            else
            {
                T temp = array[index];
                array[index] = array[rightChildIndex];
                array[rightChildIndex] = temp;
                index = rightChildIndex;
            }
        }
        else
        {
            if(array[index] > array[leftChildIndex])
            {
                T temp = array[index];
                array[index] = array[leftChildIndex];
                array[leftChildIndex] = temp;
                index = leftChildIndex;
            }
            else
            {
                break;
            }
            
            
            
        }
        

        leftChildIndex = 2 * index + 1;
        rightChildIndex = 2 * index + 2;

        // printf("swap: \n");
        // print_int_array((int*)array, mSize, 10);
    }
    
    // checkHeap(0);
    return true;
}

template<typename T>
int BinaryHeap<T>::size()
{
    return this->mSize;
}


template<typename T>
void BinaryHeap<T>::checkHeap(int index)
{
    if(index >= mSize)
    {
        return;
    }

    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if(leftChildIndex < mSize)
    {
        if(array[index] > array[leftChildIndex])
        {
            printf("Check heap error: parent [%d] is %d, left child [%d] is %d\n", index,  (int)array[index],  leftChildIndex, (int)array[leftChildIndex]);
        }
    }

    if(rightChildIndex < mSize)
    {
        if(array[index] > array[rightChildIndex])
        {
            printf("Check heap error: parent [%d] is %d, right child [%d] is %d\n", index, (int)array[index], rightChildIndex, (int)array[rightChildIndex]);
        }
    }

    checkHeap(leftChildIndex);
    checkHeap(rightChildIndex);
}


#endif