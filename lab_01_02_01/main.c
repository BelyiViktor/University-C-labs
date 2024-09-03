#include <stdio.h>
#include <math.h>

#define OK 0

#define PI (2.0 * asin(1.0))

/**
 * @brief Функция перевода радиан в градусы.
 *
 * @param degrees - градусы
 *
 * @return радианы
 */
float degrees_to_radians(float degrees);

/**
 * @brief Функция подсчёта площади трапеции.
 *
 * @param bigger_base - большее основание
 * @param lower_base - меньшее основание
 * @param angle_radians - угол при большем основании трапеции
 *
 * @return радианы
 */
float calc_square(float bigger_base, float lower_base, float angle_radians);

int main(void)
{
    float lower_base = 0, bigger_base = 0;

    printf("Введите, пожалуйста, значение a: ");
    scanf("%f", &lower_base);
    printf("Введите, пожалуйста, большую сторону: ");
    scanf("%f", &bigger_base);

    float fi_degrees = 0;
    printf("Введите, пожалуйста, угол: ");
    scanf("%f", &fi_degrees);
    float fi_radians = degrees_to_radians(fi_degrees);
    float square_of_trapezoid = calc_square(bigger_base, lower_base, fi_radians);

    printf("Полученное значение: %f\n", square_of_trapezoid);

    return OK;
}

float degrees_to_radians(float degrees)
{
    return degrees * ((float)PI / (float)180.0);
}

float calc_square(float bigger_base, float lower_base, float angle_radians)
{	
    float square;
    float eps = 0.000001f;
    if (PI / 2 - angle_radians < eps)
    {
        square = fabsf(bigger_base * lower_base);
    }
    else
        square = fabsf((bigger_base * bigger_base - lower_base * lower_base) * tanf(angle_radians) / 4);
    return square;
}

