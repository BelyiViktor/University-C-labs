#include<stdio.h>
#include<stdlib.h>

#define MAX_ARR_SIZE 10

#define OK 0
#define IO_ERROR 1
#define RUNTIME_ERROR 2

void enter_arr(int *error, int arr[MAX_ARR_SIZE], int *arr_size);

int count_product(int *error, int arr[MAX_ARR_SIZE], int arr_size);

void print_answer(int error, int answer);

int main(void)
{
    int error = OK;
    int arr[MAX_ARR_SIZE] = { 0 }, arr_size = 0;
    enter_arr(&error, arr, &arr_size);
    int answer = count_product(&error, arr, arr_size);
    print_answer(error, answer);
    return error;
}

void enter_arr(int *error, int arr[MAX_ARR_SIZE], int *arr_size)
{
    int rc = 0;
    printf("Введите, пожалуйста, размер массива: ");
    rc = scanf("%d", arr_size);
    if ((rc == 1) && (*arr_size > 0))
    {
        int does_odd_exist = 0;
        for (int i = 0; (i < *arr_size) && (*error == OK); i++)
        {
            printf("Введите, пожалуйста, элемент массива: ");
            rc = scanf("%d", arr + i);
            if (rc != 1)
            {
                printf("Ошибка: Неккоректно введён элемент массива");
                *error = IO_ERROR;
            }
            else if (abs(arr[i]) % 2 == 1)
            {
                does_odd_exist = 1;
            }
        }
        if (*error == OK && does_odd_exist == 0)
        {
            *error = IO_ERROR;
            printf("Ошибка: В массиве нет нечётного элемента");
        }
    }
    else
    {
        printf("Ошибка: Некорректно введён размер массива");
        *error = IO_ERROR;
    }
}

int count_product(int *error, int arr[MAX_ARR_SIZE], int arr_size)
{
    int product = 1;
    for (int i = 0; ((i < arr_size) && (*error == OK)); i++)
    {
        if (arr[i] != 0 && abs(arr[i]) % 2 == 1)
        {
            product *= arr[i];
        }
    }
    return product;
}

void print_answer(int error, int answer)
{
    if (error == OK)
    {
        printf("Полученный ответ: %d", answer);
    }
}
