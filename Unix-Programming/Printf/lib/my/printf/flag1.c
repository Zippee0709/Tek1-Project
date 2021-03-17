/*
** EPITECH PROJECT, 2018
** flag1.c
** File description:
** flag1.C
*/

#include "../my.h"
#include "printf.h"

void flag_o(va_list av, format_s *format)
{
    int nb = va_arg(av, unsigned int);
    my_put_unsigned_nbr_base(nb, "01234567");
}

void flag_u(va_list av, format_s *format)
{
    unsigned int nb = va_arg(av, unsigned int);
    my_put_unsigned_nbr(nb);
}

void flag_x(va_list av, format_s *format)
{
    unsigned int nb = va_arg(av, unsigned int);
    my_put_unsigned_nbr_base(nb, "0123456789abcdef");
}

void flag_X(va_list av, format_s *format)
{
    unsigned int nb = va_arg(av, unsigned int);
    my_put_unsigned_nbr_base(nb, "0123456789ABCDEF");
}
