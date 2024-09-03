#include "common_dependencies.h"
#include "input_matrix.h"
#include "input_matrix_size.h"
#include "print_matrix.h"
#include "transform_the_matrix.h"

int main(void)
{
    int return_code = OK;
    int matrix[MAX_ARR_SIZE * MAX_ARR_SIZE], rows, columns;
    input_matrix_size(&return_code, &rows, &columns);
    input_matrix(&return_code, matrix, rows, columns);
    transform_matrix(return_code, matrix, &rows, &columns);
    print_matrix(return_code, matrix, rows, columns);
    return return_code;
}