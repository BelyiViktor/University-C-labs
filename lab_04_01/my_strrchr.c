#include"consts.h"
char *my_strrchr(const char *str, int ch)
{
    const char *answer = NULL;
    for (;*str != '\0'; str++)
        if (*str == ch)
        {
            answer = str;
        }
    if (*str == ch)
    {
        answer = str;
    }
    return (char*) answer;
}
