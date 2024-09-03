#include"consts.h"
#include<stdio.h>
#include"cmp_strings.h"

int was_in_word(char symbol, char *characters_that_were)
{
    int answer = 1;
    if (characters_that_were[(int)symbol] == 0)
    {
        answer = 0;
        characters_that_were[(int)symbol]++;
    }
    return answer;
}



void form_new_str(int *return_code, char *new_str, char (*words)[MAX_WORD_SIZE + 1], int words_amount)
{
    int cur_new_str_ind = 0;
    int was_word = NO;
    for (int i = words_amount - 2; i > -1; i--)
    {
        if (i != words_amount - 2 && cmp_strings(words[i], words[words_amount - 1]))
        {
            new_str[cur_new_str_ind++] = ' ';
            was_word = YES;
        }
        char characters_that_were[ASCII_SIZE + 1] = { 0 }; 
        for (char *symbol_in_word = words[i]; *symbol_in_word != '\0' && cmp_strings(words[i], words[words_amount - 1]); symbol_in_word++)
        {
            if (!was_in_word(*symbol_in_word, characters_that_were))
                new_str[cur_new_str_ind++] = *symbol_in_word;
        }       
    }
    if (!was_word)
    {
        *return_code = EMPTY_OUT;
        printf("Ошибка: нечего выводить");
    }
}
