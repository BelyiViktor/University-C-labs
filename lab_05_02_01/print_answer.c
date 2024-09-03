#include"iowrapper.h"
#include"consts.h"

void print_answer(int return_code, int answer)
{
    if (return_code == OK)
        printf("Amount of numbers bigger than average is %d", answer);
}
