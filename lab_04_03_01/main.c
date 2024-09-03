#include"consts.h"
#include<stdio.h>
#include"input_words.h"
#include"separate_for_words.h"
#include"form_new_str.h"
#include"cut_spaces_on_the_left.h"

int main(void)
{
    int return_code = OK;
    char input_line[MAX_STRING_SIZE + 1];
    read_line(&return_code, input_line, MAX_STRING_SIZE + 1);
    char words[MAX_WORDS_AMOUNT_IN_STRING][MAX_WORD_SIZE + 1];
    int words_amount = 0;
    if (return_code == OK)
    {
        separate_for_words(&return_code, input_line, words, &words_amount);
        if (return_code == OK)
        {
            char new_str[MAX_STRING_SIZE + 1] = { 0 };
            form_new_str(&return_code, new_str, words, words_amount);
            char *cutted_str = cut_spaces_on_the_left(new_str);
            if (return_code == OK)
                printf("Result: %s\n", cutted_str);
        }
    }
    return return_code;
}
