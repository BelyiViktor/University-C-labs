#include"consts.h"
#include"is_symbol_in_sequence.h"

size_t my_strcspn(const char *str, const char *sym)
{
    size_t seq_len = 0;
    char flag = 1;
    for (; *str != '\0' && flag; str++)
        if (!is_symbol_in_sequence(*str, sym))
            seq_len++;
        else
        {
            flag = 0;
        }
    return seq_len;
}
