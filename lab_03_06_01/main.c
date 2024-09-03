#include "common_dependencies.h"
#include "input_matrix_size.h"
#include "print_matrix.h"
#include "form_matrix.h"

int main(void)
{
    int return_code = OK;
    int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE], rows, columns;
    input_matrix_size(&return_code, &rows, &columns);
    form_matrix(return_code, matrix, rows);
    print_matrix(return_code, matrix, rows, columns);
    return return_code;
}