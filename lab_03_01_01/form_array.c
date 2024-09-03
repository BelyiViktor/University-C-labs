#include "form_array.h"
#include "common_dependencies.h"
#include "check_for_symmetry.h"

void form_array(int return_code, int *arr, int *in_matrix, int rows, int columns)
{
    if (return_code == OK)
    {
        for (int i = 0; i < rows; i++)
        {
            if (check_for_symmetry(in_matrix + columns * i, columns))
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
}