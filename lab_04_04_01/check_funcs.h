#ifndef CHECK_FUNCS_H
int is_digit(char symbol);
int is_sign(char symbol);
int is_dote(char symbol);
int is_correct_before_dote_and_e(char **string, int *was_digit_before_e);
int is_end_this_of_string(char *string);
int is_correct_after_dote_before_e(char **string, int *was_digit_before_e);
int is_correct_before_e(char **string);
int is_this_exp(char symbol);
int check_it_is_exponential_form(char *string);
#endif
