#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>

#include"iowrapper.h"
#include"struct_student.h"
#include"sort_students.h"

void calc_average(FILE *students, int *students_amount, double *average)
{
    uint32_t sum = 0;
    for (int i = 0; i < *students_amount; i++)
    {
        struct student cur_student = { "None", "None", { 0, 0, 0, 0 } };
        fread(&cur_student, sizeof(struct student), 1, students);
        sum += cur_student.subject_grades[0] + cur_student.subject_grades[1] + cur_student.subject_grades[2] + cur_student.subject_grades[3];  
    }

    *average = (double) sum / (double) (4 * (*students_amount));
}

void count_remaining_students(FILE *students, double average, int students_amount, int *remaining_students)
{
    uint32_t sum = 0;
    *remaining_students = 0;
    rewind(students);
    for (int i = 0; i < students_amount; i++)
    {
        struct student cur_student = { "None", "None", { 0, 0, 0, 0 } };
        fread(&cur_student, sizeof(struct student), 1, students);
        sum = cur_student.subject_grades[0] + cur_student.subject_grades[1] + cur_student.subject_grades[2] + cur_student.subject_grades[3];
        double gpa = (double) sum / (double) 4;
        if (!(gpa < average))
        {
            *remaining_students += 1;
        }
    }
}

void pop_students(FILE *students, double average, int *students_amount, int remaining_students)
{
    uint32_t sum = 0;
    double gpa = 0;
    rewind(students);
    for (int i = 0; (i < remaining_students) && students; i++)
    {
        struct student cur_student = { "None", "None", { 0, 0, 0, 0 } };
        get_needle_student(students, i, &cur_student);
        sum = cur_student.subject_grades[0] + cur_student.subject_grades[1] + cur_student.subject_grades[2] + cur_student.subject_grades[3];
        gpa = (double) sum / (double) 4;
        while (gpa < average)
        {
            for (int j = i + 1; j < *students_amount; j++)
                swap_students(students, j - 1, j);
            get_needle_student(students, i, &cur_student);
            sum = cur_student.subject_grades[0] + cur_student.subject_grades[1] + cur_student.subject_grades[2] + cur_student.subject_grades[3];
            gpa = (double) sum / (double) 4;
        }
    }
    *students_amount = remaining_students;
}

void del_students(int *return_code, char *students_file_filename)
{
    FILE *students = fopen(students_file_filename, "rb+");
    double average = 0;
    int remaining_students = 0;
    int students_amount = 0;
    if (students)
    {
        students_amount = count_students(students);
        rewind(students);
    }
    if (students_amount && students)
    {
        calc_average(students, &students_amount, &average);
        count_remaining_students(students, average, students_amount, &remaining_students);
        pop_students(students, average, &students_amount, remaining_students);
    }
    else
        *return_code = IO_ERROR;
    if (students_amount > 0 && students)
    {
        int fd = fileno(students);
        ftruncate(fd, (students_amount) * sizeof(struct student));
        fclose(students);
    }
    else if (students)
    {
        fclose(students);
        *return_code = RUNTIME_ERROR;
    }
    else
    {
        *return_code = RUNTIME_ERROR;
    }
}
