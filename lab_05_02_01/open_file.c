#include"iowrapper.h"
#include"consts.h"

FILE *open_file(char *filename, int *return_code)
{
    FILE *f;
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error: The file cannot be opened");
        *return_code = IO_ERROR;
    }
    return f;
}
