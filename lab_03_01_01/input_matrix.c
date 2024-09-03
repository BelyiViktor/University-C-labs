#include "input_matrix.h"
#include "common_dependencies.h"



void input_matrix(int *return_code, int *matrix, int rows, int columns)
{
    if (*return_code == OK)
        printf("Введите матрицу\n");
    int i = 0, j = 0;
    while (*return_code == OK && i < rows)
    {
        printf("Введите строку матрицы: ");
        while (*return_code == OK && j < columns)
        {
            if (scanf("%d", (matrix + i * columns + j)) != 1)
            {
                printf("Ошибка: Некоректный ввод. Завершение работы программы.");
                *return_code = WRONG_INPUT;
            }
            j += 1;
        }
        i += 1;
        j = 0;
    }
}