/*
** EPITECH PROJECT, 2018
** flag.c
** File description:
** all flag for printf
*/

#include "../my.h"
#include "printf.h"

void flag_d(va_list av)
{
    int nb = va_arg(av, int);
    my_put_nbr(nb);
}

void flag_s(va_list av)
{
    char *str = va_arg(av, char *);
    my_putstr(str);
}

void flag_c(va_list av)
{
    char c = va_arg(av, int);
    my_putchar(c);
}

void flag_b(va_list av)
{
    int nb = va_arg(av, int);
    my_put_nbr_base(nb, "01");
}
