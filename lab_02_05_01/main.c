#include<stdio.h>

#define MAX_ARR_SIZE 11

#define OK 0
#define IO_ERROR 1
#define RUNTIME_ERROR 2

void enter_arr(int *error, int *arr, int **pbegin, int **pend);

int calc_sum(int *error, int *pbegin, int *pend);

void print_answer(int error, int ans);

int main(void)
{
    int error = OK;
    int arr[MAX_ARR_SIZE];
    int *pbegin, *pend;
    enter_arr(&error, arr, &pbegin, &pend);
    int ans = calc_sum(&error, pbegin, pend);
    print_answer(error, ans);

    return error;
}

void enter_arr(int *error, int *arr, int **ppbegin, int **ppend)
{
    int rc = 0;
    int arr_size;
    *ppbegin = arr;
    int *pcur = arr;
    *ppend = arr;
    printf("Введите, пожалуйста, размер массива: ");
    rc = scanf("%d", &arr_size);
    if ((rc == 1) && (arr_size > 0))
    {
        for (int i = 0; (i < arr_size) && (*error == OK); i++)
        {
            printf("Введите, пожалуйста, элемент массива: ");
            rc = scanf("%d", pcur);
            pcur++;
            *ppend += 1;
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

int calc_sum(int *error, int *pbegin, int *pend)
{
    int ans = 0;
    if (*error == OK)
    {   
        int neg_existence = 0;
        int pos_existence = 0;
        for (int *pcur_neg = pbegin, *pcur_pos = pend - 1; (pcur_neg < pend) && (pcur_pos >= pbegin); pcur_neg++)
        {
            if (*pcur_neg < 0)
            {
                neg_existence = 1;
                for (;(*pcur_pos <= 0) && (pcur_pos > pbegin); pcur_pos--);
                if (pcur_pos > pbegin)
                {
                    pos_existence = 1;
                    ans += *pcur_pos * *pcur_neg;
                }
                else if (*pcur_pos > 0)
                {
                    pos_existence = 1;
                    ans += *pcur_pos * *pcur_neg;
                }
                pcur_pos--;
            }
        }
        if (!neg_existence)
        {
            *error = RUNTIME_ERROR;
        }
        else if (!pos_existence)
        {
            *error = RUNTIME_ERROR;
        }
    }
    return ans;
}

void print_answer(int error, int ans)
{
    if (error == OK)
    {
        printf("Полученный ответ: %d", ans); 
    }
    else if (error == RUNTIME_ERROR)
        printf("Ошибка: в массиве нет положительного или отрицательного числа\n");
}
