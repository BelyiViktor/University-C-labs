#include "transform_the_matrix.h"
#include "consts.h"
#include "find_row_and_column.h"
#include "delete_row.h"
#include "delete_column.h"

void transform_matrix(int return_code, int *matrix, int *rows, int *columns)
{
    if (return_code == OK)
    {
        int column = 0, row = 0;
        find_row_and_column(matrix, *rows, *columns, &row, &column);
        delete_row(return_code, matrix, *rows, *columns, row);
        delete_column(return_code, matrix, *rows, *columns, column);
    }
}