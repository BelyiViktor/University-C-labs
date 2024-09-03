#include "delete_column.h"
#include "common_dependencies.h"
#include "get_matrix_elem_by_ref.h"

void delete_column(int return_code, int *matrix, int rows, int columns, int column)
{
    if (return_code == OK)
    {
        for (int j = column; j < columns; j++)
            for (int i = 0; i < rows; i++)
            { 
                *get_elem(matrix, columns, i, j) = *get_elem(matrix, columns, i, j + 1);
            }
    }
}