#include"consts.h"
#include"iowrapper.h"

double clalc_average(FILE *f, int *return_code)
{
    double result = 0;
    if (*return_code == OK)
    {
        double sum = 0;
        double cur_member = 0;
        int amount_of_numbers = 0;
        rewind(f);
        while (fscanf(f, "%lf", &cur_member) == 1)
        {
            amount_of_numbers++;
            sum += cur_member;
        }
        if (!feof(f))
        {
            printf("Error: File contains symbols");
            *return_code = IO_ERROR;
        }
        else if (amount_of_numbers != 0)
            result = sum / (double) amount_of_numbers;
        else
        {
            printf("Error: Out of numbers");
            *return_code = IO_ERROR;
        }
    }
    return result;
}
