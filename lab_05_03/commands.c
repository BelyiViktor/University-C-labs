#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#include"consts.h"

void create_file(char *amount_numbers_in_string, char *filename)
{
    long amount_numbers = strtol(amount_numbers_in_string, NULL, 10);
    FILE *f = fopen(filename, "wb");
    if (f)
    {
        srand(time(NULL));
        for (int i = 0; i < amount_numbers; i++)
        {
            int random_number = rand();
            fwrite(&random_number, sizeof(int), 1, f);
        }
        fclose(f);
    }
}

void export_in_binary(int *return_code, char *filename_of_text_file, char *filename_of_binary_file)
{
    FILE *textfile = fopen(filename_of_text_file, "w");
    FILE *binfile = fopen(filename_of_binary_file, "rb");
    if (textfile != NULL && binfile != NULL)
    {
        rewind(textfile);
        rewind(binfile);
        while (!feof(binfile))
        {
            int number;
            fread(&number, sizeof(int), 1, binfile);
            if (!feof(binfile))
            {
                fprintf(textfile, " %d", number);
            }
        }
    }
    else
    {
        *return_code = IO_ERROR;
        printf("Error: when opening a file");
    }
    if (textfile)
        fclose(textfile);
    if (binfile)
        fclose(binfile);
}

void import_in_text(int *return_code, char *filename_of_text_file, char *filename_of_binary_file)
{
    FILE *textfile = fopen(filename_of_text_file, "r");
    FILE *binfile = fopen(filename_of_binary_file, "wb");
    if (textfile != NULL && binfile != NULL)
    {
        rewind(textfile);
        rewind(binfile);
        int n = 0;
        while (fscanf(textfile, "%d", &n) == 1)
        {
            fwrite(&n, sizeof(int), 1, binfile);
        }
    }
    else
    {
        *return_code = IO_ERROR;
        printf("Error: when opening a file");
    }
    if (textfile)
        fclose(textfile);
    if (binfile)
        fclose(binfile);
}

