#include<stdio.h>

#define MAX_ARR_SIZE 10

#define OK 0
#define IO_ERROR 1
#define RUNTIME_ERROR 2

void enter_arr(int *error, int *arr, int *arr_size);

int is_primal(int num);

void copy_primes(int *error, int *arr, int arr_size, int *arr_of_primes, int *count_primes);

void print_answer(int error, int *arr, int arr_size);

int main(void)
{
    int error = OK;
    int arr[MAX_ARR_SIZE], arr_size;
    int arr_of_primes[MAX_ARR_SIZE], count_primes;
    enter_arr(&error, arr, &arr_size);
    copy_primes(&error, arr, arr_size, arr_of_primes, &count_primes);
    print_answer(error, arr_of_primes, count_primes);
    return error;
}

void enter_arr(int *error, int *arr, int *arr_size)
{
    int rc = 0;
    printf("Введите, пожалуйста, размер массива: ");
    rc = scanf("%d", arr_size);
    if ((rc == 1) && (*arr_size > 0))
    {
        for (int *elem = arr; (elem - arr < *arr_size) && (*error == OK); elem++)
        {
            printf("Введите, пожалуйста, элемент массива: ");
            rc = scanf("%d", elem);
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

int is_primal(int num)
{
    int is = 1;
    if (num > 1)
    {
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                is = 0;
            }
        }
    }
    else
        is = 0;
    return is;
}

void copy_primes(int *error, int *arr, int arr_size, int *arr_of_primes, int *count_primes)
{
    if (*error == OK)
    {
        *count_primes = 0;
        for (int i = 0; i < arr_size; i++)
        {
            if (is_primal(arr[i]))
            {
                arr_of_primes[*count_primes] = arr[i];
                *count_primes += 1;
            }
        }
        if (*count_primes == 0)
        {
            *error = RUNTIME_ERROR;
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
    else if (error == RUNTIME_ERROR)
    {
        printf("Ошибка: в массиве нет простых чисел");
    }
}
