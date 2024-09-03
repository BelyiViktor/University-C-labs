#include"consts.h"
#include"is_symbol_in_sequence.h"

size_t my_strspn(const char *str, const char *sym)
{
    size_t result = 0;
    char flag = 1;
    for (; *str != '\0' && flag; str++)
        if (is_symbol_in_sequence(*str, sym))
            result++;
        else
        {
            flag = 0;
        }
    return result;
}
