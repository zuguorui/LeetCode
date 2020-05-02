#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void print_int_array(int *src, int32_t len, int col);

void check_sort(int *src, int len, int inc);
#endif