#include"iowrapper.h"
#include"stdint.h"
#include"consts.h"
#include<string.h>

struct student
{
    char surname[MAX_SURNAME_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    uint32_t marks[4];
};

int was_buffer_overflow(char *buffer, int buffer_size)
{
    int was_buffer_overflow = YES;
    for (int i = 0; i < buffer_size; i++)
        if (buffer[i] == '\0')
            was_buffer_overflow = NO;
    return was_buffer_overflow;
}

void get_student_surname(char *surname, int *return_code, FILE *textfile, int *is_end_file)
{
    fscanf(textfile, "%s", surname);
    if (was_buffer_overflow(surname, MAX_SURNAME_LENGTH + 1))
        *return_code = IO_ERROR;
    else if (feof(textfile))
    {
        *is_end_file = YES;
    }
}

void get_student_name(char *name, int *return_code, FILE *textfile)
{
    fscanf(textfile, "%s", name);
    if (was_buffer_overflow(name, MAX_NAME_LENGTH + 1))
        *return_code = IO_ERROR;
}

void get_student_marks(uint32_t *marks, int *return_code, FILE *textfile)
{
    int marks_read = 0;
    int mark = 0;
    while (marks_read < 4 && *return_code == OK)
    {
        if (fscanf(textfile, "%d", &mark) == 1)
            marks[marks_read++] = mark;
        else
            *return_code = IO_ERROR;
    }
}

void convert_text_file_to_binary(int *return_code, FILE *textfile, FILE *binfile)
{
    rewind(textfile);
    rewind(binfile);
    int is_end_file = NO;
    while (!feof(textfile))
    {
        struct student current_student = { "None", "None", { 0, 0, 0, 0 } };
        get_student_surname(current_student.surname, return_code, textfile, &is_end_file);
        if (!is_end_file)
        {
            get_student_name(current_student.name, return_code, textfile);
            get_student_marks(current_student.marks, return_code, textfile);
            fwrite(&current_student, sizeof(struct student), 1, binfile);
        }
    }
}
