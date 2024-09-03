#include"iowrapper.h"
#include<string.h>
#include"struct_student.h"

int count_students(FILE *students)
{
    int result = 0;
    if (students)
    {
        int cur_pos = ftell(students);
        fseek(students, 0, SEEK_END);
        result = ftell(students) / sizeof(struct student);
        fseek(students, cur_pos, SEEK_SET);
    }
    return result;
}

void get_needle_student(FILE *students, int ind, struct student *needle_student)
{
    int cur_pos = 0;
    cur_pos = ftell(students);
    int size_of_field = sizeof(struct student);
    fseek(students, ind * size_of_field, SEEK_SET);
    fread(needle_student, size_of_field, 1, students);
    fseek(students, cur_pos, SEEK_SET);
}

void swap_students(FILE *students, int ind1, int ind2)
{
    int cur_pos = 0;
    cur_pos = ftell(students);
    int step = sizeof(struct student);
    fseek(students, step * ind1, SEEK_SET);
    struct student student1 = { "None", "None", { 0, 0, 0, 0 } };
    struct student student2 = { "None", "None", { 0, 0, 0, 0 } };
    fread(&student1, step, 1, students);
    fseek(students, step * ind2, SEEK_SET);
    fread(&student2, step, 1, students);
    fseek(students, step * ind1, SEEK_SET);
    fwrite(&student2, step, 1, students);
    fseek(students, step * ind2, SEEK_SET);
    fwrite(&student1, step, 1, students);
    fseek(students, cur_pos, SEEK_SET);
}

void sort_students(char *filename, int *return_code)
{
    FILE *students = fopen(filename, "rb+");
    int amount_students = 0;
    amount_students = count_students(students);
    for (int i = 0; i < amount_students && students; i++)
        for (int j = i + 1; j < amount_students; j++)
        {
            struct student student_i = { "None", "None", { 0, 0, 0, 0 } };
            get_needle_student(students, i, &student_i);
            struct student student_j = { "None", "None", { 0, 0, 0, 0 } };
            get_needle_student(students, j, &student_j);
            int difference = strncmp(student_i.surname, student_j.surname, MAX_SURNAME_LENGTH + 1);
            if (difference > 0)
                swap_students(students, i, j);
            else if (difference == 0 && strncmp(student_i.name, student_j.name, MAX_NAME_LENGTH + 1) > 0)
                swap_students(students, i, j);
        }
    if (!students || !amount_students)
        *return_code = IO_ERROR;
    else if (students)
        fclose(students);
}
