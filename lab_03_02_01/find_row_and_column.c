#include "find_row_and_column.h"
#include "common_dependencies.h"
#include "get_sum_of_digits.h"
#include "get_matrix_elem_by_ref.h"

void find_row_and_column(int *matrix, int rows, int columns, int *row, int *column)
{
    int cur_min = get_sum_of_digits(*get_elem(matrix, columns, 0, 0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            if (cur_min > get_sum_of_digits(*get_elem(matrix, columns, i, j)))
            {
                cur_min = get_sum_of_digits(*get_elem(matrix, columns, i, j));
                *row = i;
                *column = j;
            }
        }
}