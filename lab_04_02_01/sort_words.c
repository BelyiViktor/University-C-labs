#include"cmp_strings.h"
#include"swap_strings.h"

void sort_words(char *array_of_pointers_to_strings[], int words_amount)
{
    for (int i = 0; i < words_amount; i++)
        for (int j = i + 1; j < words_amount; j++)
        {
            if (cmp_strings(array_of_pointers_to_strings[i], array_of_pointers_to_strings[j]) > 0)
                swap_strings(array_of_pointers_to_strings, i, j);
        }
}
