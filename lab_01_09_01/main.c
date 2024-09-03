#include <stdio.h>
#include <math.h>

#define OK 0
#define WRONG_INPUT 1

double calc_argument(int *return_code);

int main(void)
{
    int return_code = OK;
    
    double argument = calc_argument(&return_code);

    if (return_code == OK)
    {
        double result = sin(argument);
        printf("%.6lf\n", result);
    }
    return return_code;
}

double calc_argument(int *return_code)
{
    double x = 0;
    double argument = 0, member = 0;
    printf("Введите, пожалуйста, x: ");
    if (scanf("%lf", &x) != 1 || x < 0)
    {
        printf("ERROR: Первое число не должно быть отрицательным\n");
        *return_code = WRONG_INPUT;
    }
    int counter = 1;
    while (x >= 0 && *return_code == OK)
    {
        member = sqrt(x / counter);
        argument += member;
        counter += 1;
        printf("Введите, пожалуйста, x: ");
        if (scanf("%lf", &x) != 1)
        {
            printf("ERROR: ошибка ввода\n");
            *return_code = WRONG_INPUT;
        }
    }
    return argument;
}
