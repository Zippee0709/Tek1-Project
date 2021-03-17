/*
** EPITECH PROJECT, 2018
** check_infin.c
** File description:
** all usefull check infin function
*/

#include "bistromatic.h"
#include "my.h"

int my_check_neg(char *nb1, char *nb2)
{
    if (nb1[0] == '-' && nb2[0] == '-')
        return (TRUE);
    else if (nb1[0] == '-' || nb2[0] == '-')
        return (2);
    return (FALSE);
}

int who_is_bigger(char *nb1, char *nb2)
{
    int i = 0;

    while (nb1[i] != '\0') {
        if (nb1[i] < nb2[i])
            return (TRUE);
        else if (nb1[i] > nb2[i])
            return (FALSE);
        i = i + 1;
    }
    return (FALSE);
}

void my_check_ret(nb_s *calc, int *j)
{
    if (calc->ret > 0) {
        calc->res[*j] = itc(calc->ret);
        *j = *j + 1;
    }
}

void my_put_neg(nb_s *calc, int *j)
{
    if (calc->neg > 0) {
        calc->res[*j] = '-';
        *j = *j + 1;
    }
}

void my_put_neg_mul(nb_s *calc)
{
    int i = 0;

    while (my_check_num(calc->res[i]) == TRUE)
        i = i + 1;
    if (calc->neg == 2) {
        calc->res[i] = '-';
        i = i + 1;
    }
    calc->res[i] = '\0';
}
