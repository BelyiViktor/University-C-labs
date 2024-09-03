#include<stdio.h>
#include<string.h>

#include"consts.h"
#include"convert_text_file_to_binary.h"
#include"convert_binary_file_to_text.h"

void export(int *return_code, char *filename_of_text_file, char *filename_of_binary_file)
{
    FILE *textfile = fopen(filename_of_text_file, "w");
    FILE *binfile = fopen(filename_of_binary_file, "rb");
    if (textfile != NULL && binfile != NULL)
        convert_binary_file_to_text(textfile, binfile);
    else
    {
        *return_code = IO_ERROR;
    }
    fclose(textfile);
    fclose(binfile);
}

void import(int *return_code, char *filename_of_text_file, char *filename_of_binary_file)
{
    FILE *textfile = fopen(filename_of_text_file, "r");
    FILE *binfile = fopen(filename_of_binary_file, "wb");
    if (textfile != NULL && binfile != NULL)
        convert_text_file_to_binary(return_code, textfile, binfile);
    else
        *return_code = IO_ERROR;
    fclose(textfile);
    fclose(binfile);
}
