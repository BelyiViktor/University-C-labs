#include<stdio.h>

void print_answer(char *array_of_words[], int words_amount)
{
    printf("Result: ");
    for (int i = 0; i < words_amount; i++)
    {
        printf("%s", array_of_words[i]);
        if (i != words_amount - 1)
            printf(" ");
    }
    printf("\n");
}
