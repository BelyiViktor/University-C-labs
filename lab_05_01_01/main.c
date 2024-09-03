#include"iowrapper.h"
#include"consts.h"
#include"process.h"
#include"print_answer.h"

int main(void)
{
    int first_max = 0, second_max = 0;
    int return_code = process(stdin, &first_max, &second_max);
    print_answer(return_code, first_max, second_max);
    return return_code;
}
