#include"consts.h"

char *my_strchr(const char *str, int ch)
{
    const char *answer = NULL;
    int flag = 1;
    for (;*str != '\0' && flag; str++)
        if (*str == ch)
        {
            answer = str;
            flag = 0;
        }
    if (*str == ch && flag)
    {
        answer = str;
        flag = 0;
    }
    return (char*) answer;
}
