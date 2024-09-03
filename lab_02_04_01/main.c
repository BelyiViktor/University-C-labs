#include<stdio.h>

#define MAX_ARR_SIZE 10

#define OK 0
#define IO_ERROR 1
#define SPECIAL_OVERFLOW_CODE 100

void enter_arr(int *error, int *arr, int *arr_size);

void insertion_sort(int *arr, int arr_size);

void inserting_fib_nums(int *arr, int *arr_size);

void print_answer(int error, int *arr, int arr_size);

int main(void)
{
    int error = OK;
    int arr[MAX_ARR_SIZE + 1], arr_size;
    enter_arr(&error, arr, &arr_size);
    insertion_sort(arr, arr_size);
    print_answer(error, arr, arr_size);
    return error;
}

void enter_arr(int *error, int *arr, int *arr_size)
{
    int elem;
    int rc = 0;
    *arr_size = 0;
    while (*arr_size < MAX_ARR_SIZE + 1 && ((rc = scanf("%d", &elem)) == 1))
    {
        arr[*arr_size] = elem;
        *arr_size += 1;
    }
    if (*arr_size == 0)
    {
        printf("Ошибка: Введён пустой массив\n");
        *error = IO_ERROR;
    }
    else if (*arr_size == MAX_ARR_SIZE + 1)
    {
        *arr_size = MAX_ARR_SIZE;
        *error = SPECIAL_OVERFLOW_CODE;
    }
}

void insertion_sort(int *arr, int arr_size)
{
    int i, key, j;
    for (i = 1; i < arr_size; i++)
    {
        key = arr[i];
        j = i - 1;
    
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_answer(int error, int *arr, int arr_size)
{
    if ((error == OK) || (error == SPECIAL_OVERFLOW_CODE))
    {
        printf("Полученный массив: ");
        for (int i = 0; i < arr_size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
