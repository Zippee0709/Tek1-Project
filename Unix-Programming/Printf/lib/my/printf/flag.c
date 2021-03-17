/*
** EPITECH PROJECT, 2018
** flag.c
** File description:
** all flag for my_printf
*/

#include "../my.h"
#include "printf.h"

void flag_d(va_list av, format_s *format)
{
    int i = 0;
    int nb = va_arg(av, int);
    format->nb_digit = my_get_nbdigit(nb);

    if (format->sign == '-') {
        my_put_nbr(nb);
        my_format_print(format);
    }
    else {
        my_format_print(format);
        my_put_nbr(nb);
    }
}

void flag_s(va_list av, format_s *format)
{
    int i = 0;
    char *str = va_arg(av, char *);
    format->nb_digit = my_strlen(str);

    if (format->sign == '-') {
        my_putstr(str);
        my_format_print(format);
    }
    else {
        my_format_print(format);
        my_putstr(str);
    }
}

void flag_c(va_list av, format_s *format)
{
    char c = va_arg(av, int);
    format->nb_digit = 1;

    if (format->sign == '-') {
        my_putchar(c);
        my_format_print(format);
    }
    else {
        my_format_print(format);
        my_putchar(c);
    }
}

void flag_b(va_list av, format_s *format)
{
    int nb = va_arg(av, int);
    char *str = my_put_nbr_base(nb, "01");
    format->nb_digit = my_strlen(str);

    if (format->sign == '-') {
        my_putstr(str);
        my_format_print(format);
        free(str);
    }
    else {
        my_format_print(format);
        my_putstr(str);
        free(str);
    }
}
