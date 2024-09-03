#include "input_matrix.h"
#include "common_dependencies.h"
#include "check_sum_of_digits.h"


void input_matrix(int *return_code, int matrix[][MAX_ARR_SIZE], int rows, int columns)
{
    if (*return_code == OK)
        printf("Введите матрицу\n");
    int i = 0, j = 0;
    int is_here_operated_number = FALSE;
    while (*return_code == OK && i < rows)
    {
        printf("Введите строку матрицы: ");
        while (*return_code == OK && j < columns)
        {
            if (scanf("%d", (matrix[i] + j)) != 1)
            {
                printf("Ошибка: Некоректный ввод. Завершение работы программы.");
                *return_code = WRONG_INPUT;
            }
            else if (check_sum_of_digits(matrix[i][j]))
                is_here_operated_number = TRUE;
            j += 1;
        }
        i += 1;
        j = 0;
    }
    if (!is_here_operated_number)
    {
        printf("Ошибка: Некоректный ввод. Завершение работы программы.");
        *return_code = WRONG_INPUT;
    }
}
