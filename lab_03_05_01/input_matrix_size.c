#include "input_matrix_size.h"
#include "common_dependencies.h"

void input_matrix_size(int *return_code, int *rows, int *columns)
{
    if (*return_code == OK)
    {
        printf("Введите количество строк: ");
        if (scanf("%d", rows) != 1 || *rows <= 0 || *rows > 10)
        {
            printf("Ошибка: Некоректный ввод. Завершение работы программы.");
            *return_code = WRONG_INPUT;
        }
        else
        {
            printf("Введите количесвтво столбцов: ");
            if (scanf("%d", columns) != 1 || *columns <= 0 || *columns > 10)
            {
                printf("Ошибка: Некоректный ввод. Завершение работы программы.");
                *return_code = WRONG_INPUT;
            }
        }
    }
}