#include<stdio.h>
#include<math.h>

#define OK 0
#define WRONG_INPUT 1

float tailor_formula(float x, float eps);

float absolute_return_code(float true_value, float s);

float relative_return_code(float true_value, float s);

void input_x(int *return_code, float *x);

void input_eps(int *return_code, float *eps);

float prepare_answer(int return_code, float x, float eps);

void print_answer(int return_code, float answer, float x);

int main(void)
{
    int return_code = OK;

    float x;
    float eps;

    input_x(&return_code, &x);

    input_eps(&return_code, &eps);

    float answer = prepare_answer(return_code, x, eps);

    print_answer(return_code, answer, x);

    return return_code;
}

float tailor_formula(float x, float eps)
{
    float result = x;
    float member = x;
    int counter = 0;

    while (fabsf(member) > eps)
    {
        counter += 2;
        member *= (x * x) / (counter * (counter + 1)) * (-1);
        result += member;
    }

    return result;
}

float absolute_return_code(float true_value, float s)
{
    return fabsf(true_value - s);
}

float relative_return_code(float true_value, float s)
{
    return absolute_return_code(true_value, s) / fabsf(true_value);
}

void input_x(int *return_code, float *x)
{
    printf("Введите, пожалуйста, значение x: ");
    int rc = scanf("%f", x);
    if (rc != 1)
    {
        *return_code = WRONG_INPUT;
        printf("ERROR: Неправильно введено первое число.");
    }
}

void input_eps(int *return_code, float *eps)
{
    int rc = 0;
    if (*return_code == OK)
    {
        printf("Введите, пожалуйста, значение эпсилон: ");
        rc = scanf("%f", eps);
    }
    if (rc != 1 && *return_code == OK)
    {
        *return_code = WRONG_INPUT;
        printf("ERROR: Неправильно введено второе число.");
    }
    else if (rc == 1 && ((*eps > 1) || (*eps <= 0)))
    {
        *return_code = WRONG_INPUT;
        printf("ERROR: Эпсилон лежит не в промежутке (0, 1].");
    }
}

float prepare_answer(int return_code, float x, float eps)
{
    float answer = 0;
    if (return_code == OK)
    {
        answer = tailor_formula(x, eps);
    }
    return answer;
}

void print_answer(int return_code, float answer, float x)
{
    if (return_code == OK)
    {
        printf("s(x) и f(x): ");
        printf("%f %f", answer, sinf(x));

        printf("\nАбсолютная и относительная погрешности: ");
        printf("%f %f", absolute_return_code(sinf(x), answer), relative_return_code(sinf(x), answer));
    }
}
