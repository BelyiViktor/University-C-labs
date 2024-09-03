#include "get_matrix_elem_by_ref.h"
int *get_elem(int *matrix, int columns, int row_ind, int column_ind)
{
    return matrix + row_ind * columns + column_ind;
}