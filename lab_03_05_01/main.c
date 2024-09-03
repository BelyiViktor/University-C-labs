#include "common_dependencies.h"
#include "input_matrix.h"
#include "input_matrix_size.h"
#include "form_array_from_matrix.h"
#include "move_arr_cyclically_left.h"
#include "form_matrix_from_arr.h"
#include "print_matrix.h"

int main(void)
{
    int return_code = OK;
    int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE], rows = 0, columns = 0;
    int arr[MAX_ARR_SIZE * MAX_ARR_SIZE], size = 0;
    input_matrix_size(&return_code, &rows, &columns);
    input_matrix(&return_code, matrix, rows, columns);
    form_array_from_matrix(return_code, matrix, rows, columns, arr, &size);
    move_arr_cyclically_left(return_code, arr, size, 3);
    form_matrix_from_array(return_code, matrix, rows, columns, arr);
    print_matrix(return_code, matrix, rows, columns);
    return return_code;
}
