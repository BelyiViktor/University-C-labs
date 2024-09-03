#include "form_array_of_pointers.h"
#include"common_dependencies.h"
void form_array_of_pointers(int return_code, int *prows[], int matrix[][MAX_ARR_SIZE], int rows)
{
    if (return_code == OK)
        for (int i = 0; i < rows; i++)
            prows[i] = matrix[i];
}