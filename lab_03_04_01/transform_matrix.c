#include "transform_matrix.h"
#include"common_dependencies.h"
#include"swap.h"

void transform_matrix(int return_code, int (*matrix)[MAX_ARR_SIZE], int rows, int columns)
{
    for (int i = 0; (return_code == OK) && (i < (int)(rows / 2)); i++)
        for (int j = i; j < columns - i; j++)
            swap(matrix[i] + j, matrix[rows - 1 - i] + j);
}
