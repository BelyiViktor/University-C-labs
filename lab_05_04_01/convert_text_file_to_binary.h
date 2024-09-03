#ifndef CONVERT_TEXT_FILE_TO_BINARY_H
#define CONVERT_TEXT_FILE_TO_BINARY_H

#include"iowrapper.h"
#include<stdint.h>

int was_buffer_overflow(char *buffer, int buffer_size);
void get_student_surname(char *surname, int *return_code, FILE *textfile, int *is_end_file);
void get_student_name(char *name, int *return_code, FILE *textfile);
void get_student_marks(uint32_t *marks, int *return_code, FILE *textfile);
void convert_text_file_to_binary(int *return_code, FILE *textfile, FILE *binfile);

#endif
