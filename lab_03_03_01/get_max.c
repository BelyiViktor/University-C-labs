#include "get_max.h"
int max_from_arr(int *arr, int n)
{
    int cur_max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > cur_max)
            cur_max = arr[i];
    return cur_max;
}