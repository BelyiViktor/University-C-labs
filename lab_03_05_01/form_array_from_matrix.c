#include "form_array_from_matrix.h"
#include"consts.h"
#include"check_sum_of_digits.h"


void form_array_from_matrix(int return_code, int matrix[][MAX_ARR_SIZE], int rows, int columns, int *arr, int *size)
{
    *size = 0;
    for (int i = 0; (i < rows) && (return_code == OK); i++)
        for (int j = 0; j < columns; j++)
        {
            if (check_sum_of_digits(matrix[i][j]))
            {
                arr[(*size)++] = matrix[i][j];
            }
        }
}
