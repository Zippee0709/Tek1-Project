/*
** EPITECH PROJECT, 2018
** flag2.c
** File description:
** flag2.c
*/

#include "../my.h"
#include "printf.h"

void flag_p(va_list av, format_s *format)
{
    int nb = va_arg(av, int);

    my_putstr("0x");
    my_put_nbr_base(nb, "0123456789abcdef");
}

void flag_mod(va_list av, format_s *format)
{
    (void)av;
    (void)format;
    my_putchar('%');
}

void flag_S(va_list av, format_s *format)
{
    char *str = va_arg(av, char *);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126) {
            my_putstr("\\00");
            my_put_nbr_base_s((int)str[i], "01234567");
        }
        else
            my_putchar(str[i]);
        i = i + 1;
    }
}
