#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <random>
#include "quick_sort.h"
#include "shell_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "tree_sort.h"
#include "util.h"

using namespace std;


static const int SRC_LEN = 200;

int main()
{
    int src[SRC_LEN];

    for(int i = 0; i < SRC_LEN; i++)
    {
        src[i] = rand() % 1000;
    }

    // quick_sort(src, 0, SRC_LEN - 1);

    // shell_sort(src, 0, SRC_LEN - 1);

    // insert_sort(src, 0, SRC_LEN - 1);

    // merge_sort(src, 0, SRC_LEN - 1);

    // heap_sort(src, 0, SRC_LEN - 1);

    printf("original array: \n");

    print_int_array(src, SRC_LEN, 10);

    tree_sort(src, 0, SRC_LEN - 1);

    print_int_array(src, SRC_LEN, 10);

    check_sort(src, SRC_LEN, 1);

    // BinaryHeap<int> heap(SRC_LEN);
    // for(int i = 0; i < SRC_LEN; i++)
    // {
    //     heap.push(src[i]);
    // }

    // for(int i = 0; i < SRC_LEN; i++)
    // {
    //     if(!heap.remove(src[i]))
    //     {
    //         printf("remove element %d error\n", src[i]);
    //     }
    // }


    getchar();

    return 0;

}