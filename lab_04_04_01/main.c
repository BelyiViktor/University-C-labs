#include"consts.h"
#include<stdio.h>
#include"read_line.h"
#include"cut_spaces_after_and_before.h"
#include"check_funcs.h"

int main(void)
{
    int return_code = OK;
    char input_line[MAX_STRING_SIZE + 1];
    read_line(&return_code, input_line, MAX_STRING_SIZE + 1);
    char *cutted_input_line = cut_spaces_after_and_before(input_line);
    if (return_code == OK && check_it_is_exponential_form(cutted_input_line))
    {
        printf("YES\n");        
    }
    else if (return_code == OK)
        printf("NO\n");
    return return_code;
}
