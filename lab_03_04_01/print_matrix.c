#include "print_matrix.h"
#include "common_dependencies.h"

void print_matrix(int return_code, int matrix[][MAX_ARR_SIZE], int rows, int columns)
{
    if (return_code == OK)
    {
        printf("Полученная матрица:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf(" %d", *(matrix[i] + j));
            }
            printf("\n");
        }
    }
}
