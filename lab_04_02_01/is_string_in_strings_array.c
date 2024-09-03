#include<string.h>
#include"consts.h"

int is_string_in_strings_array(char **strings, char *word, int strings_amount)
{
    int answer = NO;
    for (int i = 0; i < strings_amount; i++)
        if (strcmp(strings[i], word) == 0)
            answer = YES;
    return answer;
}
