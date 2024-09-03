#include "print_matrix.h"
#include "common_dependencies.h"

void print_matrix(int return_code, int *matrix, int rows, int columns)
{
    if (return_code == OK)
    {
        printf("Полученная матрица:\n");
        for (int i = 0; i < rows - 1; i++)
        {
            for (int j = 0; j < columns - 1; j++)
            {
                printf(" %d", *(matrix + columns * i + j));
            }
            printf("\n");
        }
    }
}