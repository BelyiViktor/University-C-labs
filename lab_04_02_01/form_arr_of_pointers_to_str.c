#include"consts.h"
#include"is_string_in_strings_array.h"

void form_arr_of_pointers_to_str(char **array_of_pointers_to_strings, char words[][MAX_WORD_SIZE + 1], int *words_amount)
{
    int new_words_amount = 0;
    for (int i = 0; i < *words_amount; i++)
        if (!is_string_in_strings_array(array_of_pointers_to_strings, words[i], new_words_amount))
            array_of_pointers_to_strings[new_words_amount++] = words[i];
    *words_amount = new_words_amount;
}
