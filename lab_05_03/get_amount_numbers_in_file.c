#include"iowrapper.h"

long get_amount_numbers_in_file(FILE *binfile)
{
    rewind(binfile);
    long amount_numbers = 0;
    int n = 0;
    while (fread(&n, sizeof(int), 1, binfile) == 1)
        amount_numbers++;
    return amount_numbers;
}
