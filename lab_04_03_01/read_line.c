#include"consts.h"
#include<stdio.h>
size_t read_line(int *return_code, char *s, size_t n)
{
    int ch;
    size_t i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;
        else
        {
            *return_code = INPUT_ERROR;
            printf("Ошибка: переполнение буфера.");
        }
    s[i] = '\0';
    return i;
}
