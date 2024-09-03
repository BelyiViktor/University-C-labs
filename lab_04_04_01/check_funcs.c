#include"consts.h"
#include"check_funcs.h"

int is_digit(char symbol)
{
    int answer = NO;
    if (symbol >= '0' && '9' >= symbol)
    {
        answer = YES;
    }
    return answer;
}

int is_sign(char symbol)
{
    int answer = NO;
    if (symbol == '+' || symbol == '-')
    {
        answer = YES;
    }
    return answer;
}

int is_dote(char symbol)
{
    int answer = NO;
    if (symbol == '.')
    {
        answer = YES;
    }
    return answer;
}

int is_correct_before_dote_and_e(char **string, int *was_digit_before_e)
{
    int answer = YES;
    *was_digit_before_e = is_digit(**string);
    if (is_sign(**string) || is_digit(**string) || is_dote(**string))
    {
        if (is_sign(**string))
            (*string)++;
        for (; (**string != '\0') && (**string != '.') && !is_this_exp(**string); (*string)++)
        {
            if (!is_digit(**string))
                answer = NO;
            else
                *was_digit_before_e = YES;
        }
    }
    else
        answer = NO;
    return answer;
}

int is_end_this_of_string(char *string)
{
    int answer = NO;
    if (*string == '\0')
        answer  = YES;
    return answer;
}

int is_this_exp(char symbol)
{
    int answer = NO;
    if (symbol == 'e' || symbol == 'E')
        answer = YES;
    return answer;
}

int is_correct_after_dote_before_e(char **string, int *was_digit_before_e)
{
    int answer = YES;
    for (; (**string != '\0') && !is_this_exp(**string); (*string)++)
    {
        if (!is_digit(**string))
            answer = NO;
        else
            *was_digit_before_e = YES;
    }
    return answer;
}

int is_correct_before_e(char **string)
{
    int answer = YES;
    int was_number = is_digit(**string);
    if (is_sign(**string) || is_digit(**string))
        for ((*string)++; (**string != '\0'); (*string)++)
        {
            if (!is_digit(**string))
                answer = NO;
            else
                was_number = YES;
        }
    else
        answer = NO;
    if (!was_number)
        answer = NO;
    return answer;
}

int check_it_is_exponential_form(char *string)
{
    int answer = YES;
    int was_digit_before_E = NO;
    answer = is_correct_before_dote_and_e(&string, &was_digit_before_E);
    if (answer && *string == '.')
    {
        string++;
        answer = is_correct_after_dote_before_e(&string, &was_digit_before_E);
    }
    if (answer && is_this_exp(*string))
    {
        string++;
        answer = is_correct_before_e(&string);
    }
    if (!was_digit_before_E)
        answer = NO;
    return answer;
}
