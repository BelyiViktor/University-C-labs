#include "check_sum_of_digits.h"
#include"consts.h"
#include"get_sum_of_digits.h"


int check_sum_of_digits(int num)
{
    int result = FALSE;
    if (get_sum_of_digits(num) > 10)
    {
        result = TRUE;
    }
    return result;
}
