#include"iowrapper.h"
#include"consts.h"
#include"get_number_by_pos.h"
#include"put_number_by_pos.h"
#include"get_amount_numbers_in_file.h"

void swap_numbers_in_file(FILE *binfile, long pos_first_number, long pos_second_number)
{
    int tmp = get_number_by_pos(binfile, pos_first_number);
    put_number_by_pos(binfile, pos_first_number, get_number_by_pos(binfile, pos_second_number));
    put_number_by_pos(binfile, pos_second_number, tmp);
}

int sort_numbers_in_file(char *filename)
{
    int return_code = OK;
    FILE *binfile;
    binfile = fopen(filename, "rb+");

    if (binfile == NULL)
    {
        printf("Error: The file cannot be opened");
        return_code = IO_ERROR;
    }
    if (return_code == OK)
    {
        long amount_numbers = get_amount_numbers_in_file(binfile);
        for (int i = 0; i < amount_numbers; i++)
            for (int j = i + 1; j < amount_numbers; j++)
                if (get_number_by_pos(binfile, i) > get_number_by_pos(binfile, j))
                    swap_numbers_in_file(binfile, i, j);
        if (amount_numbers == 0)
            return_code = IO_ERROR;
    }
    if (return_code == OK)
        fclose(binfile);
    return return_code;
}
