/*
** EPITECH PROJECT, 2018
** disp_stdarg.c
** File description:
** disp_stdarg
*/

#include "my.h"

int my_stdarg_flag(va_list av, char s)
{
    int i = 0;

    if (s == 'i' || s == 'd') {
        my_put_nbr(va_arg(av, int));
        my_putchar('\n');
    }
    else if (s == 's') {
        my_putstr(va_arg(av, char *));
        my_putchar('\n');
    }
    else {
        my_putchar(va_arg(av, int));
        my_putchar('\n');
    }
}

int disp_stdarg(char *s, ...)
{
    int i = 0;
    int res = 0;
    va_list av;
    va_start(av, s);

    while (s[i] != '\0') {
        my_stdarg_flag(av, s[i]);
        i = i + 1;
    }
    va_end(av);
    return (0);
}
