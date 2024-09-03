#ifndef STRUCT_STUDENT_H
#define STRUCT_STUDENT_H

#include"consts.h"
#include"stdint_wrapper.h"

struct student
{
    char surname[MAX_SURNAME_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    uint32_t subject_grades[4];
};

#endif
