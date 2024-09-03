#include"consts.h"

char *my_strpbrk(const char *str, const char *sym)
{
    const char *result = NULL;
    int flag = 1;
    for (;*sym != '\0' && flag; sym += 1)
        for (const char *symbol_in_str = str; *symbol_in_str != '\0' && flag; symbol_in_str++)
            if (*sym == *symbol_in_str)
            {
                result = symbol_in_str;
                flag = 0;
            }
    return (char*) result;
}
