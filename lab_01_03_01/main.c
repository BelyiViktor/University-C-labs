#include <stdio.h>
#include <math.h>

#define OK 0

/**
 *@brief Функция возвращает объём смеси 2 стаканов.
 *
 *@param volume_1 - объём первого стакана
 *@param volume_2 - объём второго стакана
 *
 *@return объём смеси
 */
float get_volume(float volume_1, float volume_2);

/**
 *@brief Функция возвращает температуру смеси 2 стаканов.
 *
 *@param temperature_1 - температура первого стакана
 *@param volume_1 - объём первого стакана
 *@param temperature_2 - температура второго стакана
 *@param volume_2 - объём второго стакана
 *
 *@return объём смеси
 */
float get_temperature(float temperature_1, float volume_1, float temperature_2, float volume_2);

/**
 * @brief Функция - точка входа в программу.
 * @return 0 в случае верного выполнения программы.
 */

int main(void)
{
    float volume_1 = 0, temperature_1 = 0;
    float volume_2 = 0, temperature_2 = 0;

    printf("Введите, пожалуйста, объём в первом стакане: ");
    scanf("%f", &volume_1);
    printf("Введите, пожалуйста, температуру в первом стакане: ");
    scanf("%f", &temperature_1);
    printf("Введите, пожалуйста, объём во втором стакане: ");
    scanf("%f", &volume_2);
    printf("Введите, пожалуйста, температуру во втором стакане: ");
    scanf("%f", &temperature_2);

    float v_mixture = get_volume(volume_1, volume_2);
    float t_mixture = get_temperature(temperature_1, volume_1, temperature_2, volume_2);

    printf("Объём и температура смеси соответственно: %f %f", v_mixture, t_mixture);

    return OK;
}

float get_volume(float volume_1, float volume_2)
{
    return volume_1 + volume_2;
}

float get_temperature(float temperature_1, float volume_1, float temperature_2, float volume_2)
{
    return (temperature_1 * volume_1 + temperature_2 * volume_2) / (volume_1 + volume_2);
}
