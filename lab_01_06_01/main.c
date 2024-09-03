#include<stdio.h>
#include<math.h>

#define OK 0
#define WRONG_INPUT 1
#define WRONG_FIGURE 2
#define EPS 0.000001f

/**
 * @brief Функция нахождения площади треугольника по его координатам
 *
 * return площадь треугольника
 */
float get_triangle_area(float xa, float ya, float xb, float yb, float xc, float yc);

int is_zero(float num, float eps);

void input_point(int *return_code, float *x, float *y);

int main(void)
{
    int return_code = OK;

    float xa, ya;
    printf("Введите, пожалуйста, координаты вершины А\n");
    input_point(&return_code, &xa, &ya);
    float xb, yb;
    printf("Введите, пожалуйста, координаты вершины B\n");
    input_point(&return_code, &xb, &yb);
    float xc, yc;
    printf("Введите, пожалуйста, координаты вершины C\n");
    input_point(&return_code, &xc, &yc);

    if (return_code == OK)
    {
        float triangle_area = get_triangle_area(xa, ya, xb, yb, xc, yc);
        if (is_zero(triangle_area, EPS))
        {
            printf("return_code: Введённая точки не являются вершинами треугольника");
            return_code = WRONG_FIGURE;
        }
        else
            printf("Полученная площадь треугольника: %f \n", triangle_area);
    }
    return return_code;
}

int is_zero(float num, float eps)
{
    return num > -eps && num < eps;
}

float get_triangle_area(float xa, float ya, float xb, float yb, float xc, float yc)
{
    return (float)0.5 * fabsf((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}

void input_point(int *return_code, float *x, float *y)
{
    int successfully_entered;
    if (*return_code == OK)
    {
        printf("Введите, пожалуйста, координату x вершины: ");
        successfully_entered = scanf("%f", x);
        if (successfully_entered != 1)
        {
            printf("return_code: Неправильный ввод координаты x вершины.");
            *return_code = WRONG_INPUT;
        }
    }
    if (*return_code == OK)
    {
        printf("Введите, пожалуйста, координату у вершины: ");
        successfully_entered = scanf("%f", y);
        if (successfully_entered != 1)
        {
            printf("return_code: Неправильный ввод координаты у вершины.");
            *return_code = WRONG_INPUT;
        }
    }
}
