/*
** EPITECH PROJECT, 2018
** format.c
** File description:
** format
*/

#include "../my.h"
#include "printf.h"

char check_flags(char *str, int *nb)
{
    int i = 0;
    char sign = 0;

    while (str[*nb] == '#')
        *nb = *nb + 1;
    while (str[*nb] == '+' || str[*nb] == '-') {
        if (str[*nb] == '+' && i == 0)
            sign = '+';
        else {
            sign = '-';
            i = 1;
        }
        *nb = *nb + 1;
    }
    return (sign);
}

int check_field_width(char *str, int *nb)
{
    int save = 0;

    while (str[*nb] >= '0' && str[*nb] <= '9') {
        save = save * 10;
        save = save + str[*nb] - '0';
        *nb = *nb + 1;
    }
    return (save);
}

int check_precision(char *str, int *nb)
{
    int save = 0;

    if (str[*nb] == '.') {
        *nb = *nb + 1;
        while (str[*nb] >= '0' && str[*nb] <= '9') {
            save = save * 10;
            save = save + str[*nb] - '0';
            *nb = *nb + 1;
        }
    }
    return (save);
}

void check_format(char *str, int *nb, format_s *format)
{
    format->sign = check_flags(str, nb);
    format->field = check_field_width(str, nb);
    format->precision = check_precision(str, nb);
}

void my_format_print(format_s *format)
{
    int nb_space = format->field - format->nb_digit;

    while (nb_space > 0) {
        my_putchar(' ');
        nb_space = nb_space - 1;
    }
}
