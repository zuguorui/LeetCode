#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <random>
#include "quick_sort.h"
#include "shell_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "util.h"

using namespace std;








static const int SRC_LEN = 20;

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

    // print_int_array(src, SRC_LEN, 6);

    merge_sort(src, 0, SRC_LEN - 1);

    print_int_array(src, SRC_LEN, 6);

    check_sort(src, SRC_LEN, 1);

    long a = 0;

    // printf("size of long = %d\n", sizeof(a));

    getchar();

    return 0;

}