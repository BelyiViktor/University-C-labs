#include "get_sum_of_digits.h"
int get_sum_of_digits(int num)
{
    if (num < 0)
        num *= -1;
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num = (num - num % 10) / 10;
    }
    return sum;
}
