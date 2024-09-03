#include"iowrapper.h"
#include"consts.h"
#include<stdint.h>
#include"struct_student.h"

void print_students(char *filename)
{
    FILE *students = fopen(filename, "rb+");
    if (students)
    {
        rewind(students);
        while (!feof(students))
        {
            struct student curent_strudent = { "None", "None", { 0, 0, 0, 0 } };
            fread(&curent_strudent, sizeof(struct student), 1, students);
            if (!feof(students))
            {
                printf("%s\n", curent_strudent.surname);
                printf("%s\n", curent_strudent.name);
                printf("%d\n", curent_strudent.subject_grades[0]);
                printf("%d\n", curent_strudent.subject_grades[1]);
                printf("%d\n", curent_strudent.subject_grades[2]);
                printf("%d\n", curent_strudent.subject_grades[3]);
            }
        }
        fclose(students);
    }
}