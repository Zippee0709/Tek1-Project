/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** func.C
*/

#include "my.h"
#include "infinadd.h"

int cti(char c)
{
    int res = c - '0';
    return (res);
}

char itc(int c)
{
    char res = c + '0';
    return (res);
}

int my_check_negative(char *s1, char *s2)
{
    if (s1[0] == '-' && s2[0] == '-')
        return (1);
    else if (s1[0] == '-' || s2[0] == '-')
        return (2);
    return (0);
}

void one_is_negativ(infin_t *infin)
{
    int nb1 = my_check_size(infin->s1);
    int nb2 = my_check_size(infin->s2);

    if (my_who_is_neg(infin->s1) == 0 && nb1 > nb2)
        infinsub(infin->s1, infin->s2, infin);
    else if (my_who_is_neg(infin->s1) == 1 && nb1 < nb2)
        infinsub(infin->s2, infin->s1, infin);
    else if (my_who_is_neg(infin->s2) == 0 && nb1 >= nb2) {
        infinsub(infin->s1, infin->s2, infin);
        my_put_sup_neg(infin->res);
    }
    else if (my_who_is_neg(infin->s2) == 1 && nb1 >= nb2) {
        infinsub(infin->s2, infin->s1, infin);
        my_put_sup_neg(infin->res);
    }
    my_revstr(infin->res);
    my_print_sup_res(infin->res);
}

void my_call_func(infin_t *infin)
{
    if (infin->neg == 1 || infin->neg == 0)
        my_check_lenght(infin);
    else
        one_is_negativ(infin);
}
