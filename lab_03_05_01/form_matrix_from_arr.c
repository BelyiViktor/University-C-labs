#include "form_matrix_from_arr.h"
#include"consts.h"
#include"check_sum_of_digits.h"

void form_matrix_from_array(int return_code, int matrix[][MAX_ARR_SIZE], int rows, int columns, int *arr)
{
    int ind_cur_number_for_replacement = 0;
    for (int i = 0; (i < rows) && (return_code == OK); i++)
        for (int j = 0; j < columns; j++)
        {
            if (check_sum_of_digits(matrix[i][j]))
                matrix[i][j] = arr[ind_cur_number_for_replacement++];
        }
}
