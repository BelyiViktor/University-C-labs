#ifndef SORT_STUDENTS_H
#define SORT_STUDENTS_H

#include"iowrapper.h"
#include"struct_student.h"

int count_students(FILE *students);
void get_needle_student(FILE *students, int ind, struct student *needle_student);
void swap_students(FILE *students, int ind1, int ind2);
void sort_students(char *filename, int *return_code);

#endif
