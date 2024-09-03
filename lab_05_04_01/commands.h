#ifndef COMMANDS_H
#define COMMANDS_H

void create_file(char *amount_numbers, int *return_code, char *filename);
void export(int *return_code, char *filename_of_text_file, char *filename_of_binary_file);
void import(int *return_code, char *filename_of_text_file, char *filename_of_binary_file);

#endif
