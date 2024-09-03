char *cut_spaces_after_and_before(char *str)
{
    char *last_nonspace = str;
    for (char *symbol = str; *symbol != '\0'; symbol++)
        if (*symbol != ' ' && *symbol != '\t')
            last_nonspace = symbol;
    if (*str != '\0')
        *(++last_nonspace) = '\0'; 
    for (; *str == ' ' || *str == '\t'; str++);
    return str;
}
