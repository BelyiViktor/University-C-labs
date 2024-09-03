#include<string.h>
#include<stdio.h>
#include"my_str_funcs.h"

int main(void)
{
    int count_failures = 0;
    char string[] = "Hello, world!";
    char selection_1[] = "lw";
    if (!(my_strpbrk(string, selection_1) == strpbrk(string, selection_1)))
        count_failures++;
    if (!(my_strspn(string, selection_1) == strspn(string, selection_1)))
        count_failures++;
    char selection_2[] = "a";
    if (!(my_strcspn(string, selection_2) == strcspn(string, selection_2)))
        count_failures++;
    if (!(my_strchr(string, 'H') == strchr(string, 'H')))
        count_failures++;
    if (!(my_strchr(string, '\0') == strchr(string, '\0')))
        count_failures++;
    if (!(my_strrchr(string, 'o') == strrchr(string, 'o')))
        count_failures++;
    if (!(my_strrchr(string, '\0') == strrchr(string, '\0')))
        count_failures++;
    printf("%d", count_failures);
    return 0;
}
