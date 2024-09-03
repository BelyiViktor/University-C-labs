#include<stdio.h>

#define OK 0
#define WRONG_INPUT 1

void input_wrapper(int *return_code, int *ref_for_number);
void calc_div_and_quot(int *quotient, int *remainder, int number, int divider);

int main(void)
{
    int return_code = OK;

    int number = 0, divider = 0;
    printf("Введите, пожалуйста, делимое: ");
    input_wrapper(&return_code, &number);
    if (return_code == OK)
    {
        printf("Введите, пожалуйста, делитель: ");
        input_wrapper(&return_code, &divider);
    }
    if (return_code == OK)
    {
        int quotient;
        int remainder;
        calc_div_and_quot(&quotient, &remainder, number, divider);
        printf("Частное и остаток от деления: %d %d \n", quotient, remainder);
    }
    return return_code;
}

void input_wrapper(int *return_code, int *ref_for_number)
{
    if (*return_code == OK)
    {
        int rc = scanf("%d", ref_for_number);
        if (rc != 1 || *ref_for_number <= 0)
        {
            printf("return_code: Ошибка ввода");
            *return_code = WRONG_INPUT;
        }
    }
}

void calc_div_and_quot(int *quotient, int *remainder, int number, int divider)
{
    for (*quotient = 0; number - divider >= 0; (*quotient)++)
    {
        number -= divider;
    }
    *remainder = number;
}
