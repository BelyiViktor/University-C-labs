#include"consts.h"
#include"is_symbol_in_sequence.h"

void separate_for_words(int *return_code, char *origin_string, char words[][MAX_WORD_SIZE + 1], int *words_amount)
{
    int index_of_symbol_in_word = 0;
    *words_amount = 0;
    int was_word = 0;
    for (; *origin_string != '\0' && (*return_code == 0); origin_string++)
    {
        if (!(is_symbol_in_sequence(*origin_string, DELIMER_SEQUENCE)) && index_of_symbol_in_word < MAX_WORD_SIZE)
        {
            was_word = 1;
            words[*words_amount][index_of_symbol_in_word++] = *origin_string;
        }
        else if (index_of_symbol_in_word == 16)
            *return_code = INPUT_ERROR;
        else if (was_word)
        {
            was_word = 0;
            words[*words_amount][index_of_symbol_in_word] = '\0';
            index_of_symbol_in_word = 0;
            (*words_amount)++;
        }
    }
    if (was_word && (*return_code == 0))
    {
        words[*words_amount][index_of_symbol_in_word] = '\0';
        (*words_amount)++;
    }
    if (*words_amount == 0)
        *return_code = INPUT_ERROR;
}
