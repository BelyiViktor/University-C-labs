#include "common_dependencies.h"
#include "input_matrix.h"
#include "input_matrix_size.h"
#include "print_array.h"
#include "form_array.h"

int main(void)
{
    int return_code = OK;
    int in_matrix[MAX_ARR_SIZE * MAX_ARR_SIZE], rows, columns;
    int out_arr[MAX_ARR_SIZE], out_arr_size;
    input_matrix_size(&return_code, &rows, &columns, &out_arr_size);
    input_matrix(&return_code, in_matrix, rows, columns);
    form_array(return_code, out_arr, in_matrix, rows, columns);
    print_array(return_code, out_arr, out_arr_size);
    return return_code;
}