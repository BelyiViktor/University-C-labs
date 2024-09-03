#include"iowrapper.h"
#include"consts.h"

int process(FILE *f, int *first_max, int *second_max)
{
    int return_code = OK;
    int n = 0;
    int count_numbers = 0;
    while (fscanf(f, "%d", &n) == 1)
    {
        if (!count_numbers)
        {
            *first_max = n;
            *second_max = n;
        }
        else if (n > *first_max)
        {
            *second_max = *first_max;
            *first_max = n;
        }
        count_numbers += 1;
    }
    if (count_numbers > 1)
        return_code = OK;
    else
        return_code = IO_ERROR;
    return return_code;
}
