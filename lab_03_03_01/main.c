#include "common_dependencies.h"
#include "input_matrix.h"
#include "input_matrix_size.h"
#include "print_matrix.h"
#include "sort_matrix.h"
#include "form_array_of_pointers.h"

int main(void)
{
    int return_code = OK;
    int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE], rows, columns;
    int *prows[MAX_ARR_SIZE];
    input_matrix_size(&return_code, &rows, &columns);
    input_matrix(&return_code, matrix, rows, columns);
    form_array_of_pointers(return_code, prows, matrix, rows);
    sort_matrix(return_code, prows, rows, columns);
    print_matrix(return_code, prows, rows, columns);
    return return_code;
}