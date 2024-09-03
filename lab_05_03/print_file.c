#include"iowrapper.h"
#include"consts.h"
#include"consts.h"

int print_file(char *filename)
{
    int return_code = OK;
    FILE *bin_file = fopen(filename, "rb");
    if (bin_file)
    {
        int was_number = NO;
        int number;
        while (fread(&number, sizeof(int), 1, bin_file) == 1)
        {    
            printf("%d ", number);
            was_number = YES;
        }
        if (!was_number)
            return_code = IO_ERROR;
    }
    else
    {
        printf("Error: Unable to open file");
        return_code = IO_ERROR;
    }
    return return_code;
}