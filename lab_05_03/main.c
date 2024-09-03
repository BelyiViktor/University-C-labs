#include"iowrapper.h"
#include"consts.h"
#include<string.h>
#include<unistd.h>
#include<time.h>
#include"print_file.h"
#include"sort_numbers_in_file.h"
#include<stdlib.h>
#include"commands.h"

int main(int argc, char **argv)
{
    int return_code = OK;
    
    if (!strncmp(argv[1], "c", 2) && argc == 4)
        create_file(argv[2], argv[3]);
    else if (!strncmp(argv[1], "p", 2) && argc == 3)
        return_code = print_file(argv[2]);
    else if (!strncmp(argv[1], "s", 2) && argc == 3)
        return_code = sort_numbers_in_file(argv[2]);
    else if (!strncmp(argv[1], "export", 7) && argc == 4)
    {
        export_in_binary(&return_code, argv[3], argv[2]);
    }
    else if (!strncmp(argv[1], "import", 7) && argc == 4)
    {
        import_in_text(&return_code, argv[2], argv[3]);
    }
    else
    {
        printf("Error: Args error");
        return_code = ARGS_ERROR;
    }
    return return_code;
}
