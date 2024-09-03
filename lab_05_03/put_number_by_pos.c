#include"iowrapper.h"

int put_number_by_pos(FILE *binfile, long number_pos, int number)
{
    rewind(binfile);
    fseek(binfile, sizeof(int) * number_pos, SEEK_SET);
    fwrite(&number, sizeof(int), 1, binfile);
    return number;
}
