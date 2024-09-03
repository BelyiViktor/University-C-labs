#include"iowrapper.h"
#include"consts.h"
#include"calc_average.h"
#include"count_bigger_than_number.h"

int do_calculations(FILE *f, int *return_code)
{
    int answer = 0;
    if (*return_code == OK)
    {
        double average = clalc_average(f, return_code);
        answer = count_bigger_than_number(f, *return_code, average);
        fclose(f);
    }
    return answer;
}