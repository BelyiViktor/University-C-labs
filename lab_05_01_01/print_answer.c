#include"iowrapper.h"

void print_answer(int return_code, int first_max, int second_max)
{
    if (!return_code)
    {
        printf("First maximum: %d \nSecond maximum: %d \n", first_max, second_max);
    }
    else
        printf("Error: input is incorrect.\n");    
}
