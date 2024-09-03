#include "sort_matrix.h"
#include"get_max.h"
#include"consts.h"
#include"swap.h"

void sort_matrix(int return_code, int *matrix[], int rows, int columns)
{
    for (int i = 0; (i < rows) && (return_code == OK); i++)
        for (int j = 0; j < rows; j++)
            if (max_from_arr(matrix[i], columns) > max_from_arr(matrix[j], columns))
            {
                swap(matrix + i, matrix + j);
            }
}
