void swap_strings(char *array_of_pointers_to_strings[], int i, int j)
{
    char *tmp = array_of_pointers_to_strings[i];
    array_of_pointers_to_strings[i] = array_of_pointers_to_strings[j];
    array_of_pointers_to_strings[j] = tmp;
}
