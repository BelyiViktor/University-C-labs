char *cut_spaces_on_the_left(char *string)
{
    for (; *string == ' '; string++);
    return string;
}
