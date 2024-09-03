#include"iowrapper.h"
#include"consts.h"
#include<string.h>
#include"convert_text_file_to_binary.h"
#include"convert_binary_file_to_text.h"
#include"sort_students.h"
#include"find_and_show_students.h"
#include"del_students.h"
#include<stdlib.h>
#include<unistd.h>
#include"struct_student.h"
#include"print_students.h"
#include"commands.h"


int main(int argc, char **argv)
{
    int return_code = OK;
    if (argc == 3 && (!strncmp(argv[1], "sb", 3)))
    {
        sort_students(argv[2], &return_code);
        print_students(argv[2]);
    }
    else if (argc == 5 && (!strncmp(argv[1], "fb", 3)))
        find_and_show_students(&return_code, argv[2], argv[3], argv[4]);
    else if (argc == 3 && !strncmp(argv[1], "db", 3))
    {
        del_students(&return_code, argv[2]);
    }
    else if (argc == 4 && (!strncmp(argv[1], "import", 7)))
    {
        import(&return_code, argv[2], argv[3]);
    }
    else if (argc == 4 && !strncmp(argv[1], "export", 7))
    {
        export(&return_code, argv[3], argv[2]);
    }
    else
    {
        return_code = ARGS_ERROR;
    }
    return return_code;
}
