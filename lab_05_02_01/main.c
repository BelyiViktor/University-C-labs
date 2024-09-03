#include"iowrapper.h"
#include"consts.h"
#include"open_file.h"
#include"do_calculations.h"
#include"print_answer.h"


int main(int argc, char **argv)
{
    FILE *f;
    int answer = 0;
    int return_code = OK;
    if (argc != 2)
    {
        printf("ERROR: Too many params");
        return_code = ARGS_ERROR;
    }
    else
    {
        f = open_file(argv[1], &return_code);
        answer = do_calculations(f, &return_code);
        print_answer(return_code, answer);
    }
    return return_code;
}
