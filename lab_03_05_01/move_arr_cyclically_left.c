#include "move_arr_cyclically_left.h"
#include"consts.h"

void move_arr_cyclically_left(int return_code, int *arr, int size, int offset)
{
    for (int k = 0; (k < offset) && (return_code == OK); k++)
    {
        int tmp = arr[0];
        for (int i = 0; i < size; i++)
            arr[i] = arr[i + 1];
        arr[size - 1] = tmp;
    }
}
