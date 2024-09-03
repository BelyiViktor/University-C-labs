#include "print_array.h"
#include "common_dependencies.h"

void print_array(int return_code, int *arr, int arr_size)
{
    if (return_code == OK)
    {
        printf("Полученный массив: ");
        for (int i = 0; i < arr_size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}