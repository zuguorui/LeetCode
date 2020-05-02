#include "util.h"

void print_int_array(int *src, int32_t len, int col)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d, ", src[i]);
        if((i + 1) % col == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

void check_sort(int *src, int len, int inc)
{
    for(int i = 0; i < len - 1; i++)
    {
        if(i != 0)
        {
            if(inc == 1)
            {
                if(src[i] > src[i + 1])
                {
                    printf("check increase sort error, src[%d] = %d, src[%d] = %d\n", i, src[i], i + 1, src[i + 1]);
                }
            }else
            {
                if(src[i] < src[i + 1])
                {
                    printf("check decrease sort error, src[%d] = %d, src[%d] = %d\n", i, src[i], i + 1, src[i + 1]);
                }
            }
            
        }
    }
    printf("check finished\n");
}
