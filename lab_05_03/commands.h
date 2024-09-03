#ifndef COMMANDS_H
#define COMMANDS_H

void create_file(char *amount_numbers, char *filename);
void export_in_binary(int *return_code, char *filename_of_text_file, char *filename_of_binary_file);
void import_in_text(int *return_code, char *filename_of_text_file, char *filename_of_binary_file);

#endif
