#include"consts.h"

int cmp_strings(char *string1, char *string2)
{
    int difference = 0;
    int was_different_symbol = NO;
    for (; *string1 != '\0' && *string2 != '\0'; string1++, string2++)
        if (*string1 != *string2)
        {
            difference = *string1 - *string2;
            was_different_symbol = YES;
        }
    if (!was_different_symbol && (*string1 == '\0') && (*string2 == '\0'))
        difference = 0;
    else if (!was_different_symbol && (*string1 == '\0'))
        difference = 0 - *string2;
    else if (!was_different_symbol && (*string2 == '\0'))
    {
        difference = *string1 - 0;
    }
    return difference;
}
