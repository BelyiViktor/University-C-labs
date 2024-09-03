#include<stdio.h>

#define MAX_ARR_SIZE 20
#define DIVIDER 3

#define OK 0
#define IO_ERROR 1

void enter_arr(int *error, int *arr, int *arr_size);

int is_divisible(int num);

void swap(int *x, int *y);

int get_cur_fib(int *f1, int *f2);

void insert_after(int *arr, int *arr_size, int ind_where, int cur_fib);

void inserting_fib_nums(int *error, int *arr, int *arr_size);

void print_answer(int error, int *arr, int arr_size);

int main(void)
{
    int error = OK;
    int arr[MAX_ARR_SIZE] = { 0 }, arr_size = 0;
    enter_arr(&error, arr, &arr_size);
    inserting_fib_nums(&error, arr, &arr_size);
    print_answer(error, arr, arr_size);
    return error;
}

void enter_arr(int *error, int *arr, int *arr_size)
{
    int rc = 0;
    printf("Введите, пожалуйста, размер массива: ");
    rc = scanf("%d", arr_size);
    if ((rc == 1) && (*arr_size > 0))
    {
        for (int i = 0; (i < *arr_size) && (*error == OK); i++)
        {
            printf("Введите, пожалуйста, элемент массива: ");
            rc = scanf("%d", &arr[i]);
            if (rc != 1)
            {
                printf("Ошибка: Неккоректно введён элемент массива");
                *error = IO_ERROR;
            }
        }
    }
    else
    {
        printf("Ошибка: Некорректно введён размер массива");
        *error = IO_ERROR;
    }
}

int is_divisible(int num)
{
    int is = 0;
    if (num % DIVIDER == 0)
    {
        is = 1;
    }
    else
        is = 0;
    return is;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int get_cur_fib(int *f1, int *f2)
{
    int cur_fib = *f1;
    int tmp = *f2;
    *f2 = *f2 + *f1;
    *f1 = tmp;
    return cur_fib;
}

void insert_after(int *arr, int *arr_size, int ind_where, int cur_fib)
{
    for (int i = *arr_size; i > ind_where; i--)
    {
        swap(arr + i, arr + (i - 1));
    }
    *arr_size += 1;
    arr[ind_where] = cur_fib;
}

void inserting_fib_nums(int *error, int *arr, int *arr_size)
{
    int f1 = 0, f2 = 1;
    for (int i = 0; i < *arr_size && (*error == OK); i++)
    {
        if (is_divisible(arr[i]))
        {
            insert_after(arr, arr_size, i + 1, get_cur_fib(&f1, &f2));
            i++;
        }
    }
}

void print_answer(int error, int *arr, int arr_size)
{
    if (error == OK)
    {
        printf("Полученный массив: ");
        for (int i = 0; i < arr_size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
