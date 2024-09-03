#include"consts.h"

size_t is_symbol_in_sequence(char symbol, const char *sequence)
{
    size_t answer = 0;
    size_t flag = 1;
    for (; *sequence != '\0' && flag; sequence++)
        if (symbol == *sequence)
        {
            answer = 1;
            flag = 0;
        }
    return answer;
}
