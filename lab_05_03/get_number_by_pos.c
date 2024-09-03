#include"iowrapper.h"

int get_number_by_pos(FILE *binfile, long number_pos)
{
    int number = 0;
    rewind(binfile);
    fseek(binfile, sizeof(int) * number_pos, SEEK_SET);
    fread(&number, sizeof(int), 1, binfile);
    return number;
}
