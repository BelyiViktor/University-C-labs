#include "delete_row.h"
#include "common_dependencies.h"
#include "get_matrix_elem_by_ref.h"

void delete_row(int return_code, int *matrix, int rows, int columns, int row)
{
    if (return_code == OK)
    {
        for (int i = row; i < rows - row; i++)
            for (int j = 0; j < columns; j++)
            { 
                *get_elem(matrix, columns, i, j) = *get_elem(matrix, columns, i + 1, j);
            }    
    }
}