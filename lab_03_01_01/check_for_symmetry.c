#include "check_for_symmetry.h"
#include "common_dependencies.h"

int check_for_symmetry(int *arr, int size_of_arr)
{
    int result = TRUE;
    for (int i = 0; i < (int) (size_of_arr / 2); i += 1)
    {
        if (arr[i] != arr[size_of_arr - i - 1])
            result = FALSE;
    }
    return result;
}
