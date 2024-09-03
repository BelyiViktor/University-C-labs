#include<string.h>
#include"iowrapper.h"
#include"struct_student.h"


void copy_appropriate_students(int *return_code, FILE *file_src, FILE *file_dst, char *substr)
{
    struct student current_student = { "None", "None", { 0, 0, 0, 0 } };
    rewind(file_src);
    int rc = 0;
    int was_student = NO;
    while (!feof(file_src))
    {
        rc = fread(&current_student, sizeof(struct student), 1, file_src);
        if (!strncmp(current_student.surname, substr, strlen(substr)) && rc)
        {
            was_student = YES;
            fwrite(&current_student, sizeof(struct student), 1, file_dst);
        }
    }
    if (!was_student)
        *return_code = RUNTIME_ERROR;
}


void find_and_show_students(int *return_code, char *filename_src, char *filename_dst, char *substr)
{
    FILE *file_src = fopen(filename_src, "rb");
    FILE *file_dst = fopen(filename_dst, "wb");
    int amount_students = 0;
    if (file_dst && file_src)
    {
        fseek(file_src, 0, SEEK_END);
        amount_students = ftell(file_src);
    }
    if (amount_students && file_dst && file_src)
    {
        copy_appropriate_students(return_code, file_src, file_dst, substr);
    }
    else
        *return_code = IO_ERROR;
    if (file_src)
        fclose(file_src);
    if (file_dst)
        fclose(file_dst);
}
