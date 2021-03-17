/*
** EPITECH PROJECT, 2018
** sum_stdarg.c
** File description:
** sum_stdarg
*/

#include "my.h"

int my_sum_nb(int i, int nb, va_list av)
{
    i = 0;

    while (nb != 0) {
        i = i + va_arg(av, int);
        nb = nb - 1;
    }
    return (i);
}

int my_sum_str(int i, int nb, va_list av)
{
    i = 0;

    while (nb != 0) {
        i = i + my_strlen(va_arg(av, char *));
        nb = nb - 1;
    }
    return (i);
}

int sum_stdarg(int i, int nb, ...)
{
    int res = 0;
    va_list av;
    va_start(av, nb);

    if (i == 0)
        res = my_sum_nb(i, nb, av);
    else if (i == 1)
        res = my_sum_str(i, nb, av);
    else
        return (84);
    return (res);
}
