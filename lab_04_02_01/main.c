#include"consts.h"
#include"input_words.h"
#include"form_arr_of_pointers_to_str.h"
#include"sort_words.h"
#include"print_answer.h"

int main(void)
{
    int return_code = OK;
    char input_line[MAX_STRING_SIZE + 1] = { 0 };
    read_line(&return_code, input_line, MAX_STRING_SIZE + 1);
    char words[MAX_WORDS_AMOUNT_IN_STRING][MAX_WORD_SIZE + 1] = { 0 };
    int words_amount = 0;
    if (return_code == OK)
    {
        separate_for_words(&return_code, input_line, words, &words_amount);
        if (return_code == OK)
        {
            char *array_of_pointers_to_strings[MAX_WORDS_AMOUNT_IN_STRING] = { 0 };
            form_arr_of_pointers_to_str(array_of_pointers_to_strings, words, &words_amount);
            sort_words(array_of_pointers_to_strings, words_amount);
            print_answer(array_of_pointers_to_strings, words_amount);
        }
    }
    return return_code;
}
