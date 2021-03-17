/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../my.h"
#include "printf.h"

void tab_func(va_list av, int *i, format_s *format)
{
    tpsf tab_func[12] = {flag_d, flag_d, flag_o, flag_u, flag_x,
                         flag_X, flag_c, flag_s, flag_S, flag_p,
                         flag_b, flag_mod};
    (*tab_func[*i])(av, format);
}

int my_check_num_arg(char letter)
{
    int i = 0;
    char *str = "diouxXcsSpb%";

    while (str[i] != '\0') {
        if (str[i] == letter)
            return (i);
        i = i + 1;
    }
    return (-1);
}

void my_check_mod(char *str, va_list av, int *nb)
{
    int i = 0;
    format_s format;

    if (str[*nb] == '%' && str[*nb + 1] != '\0') {
        *nb = *nb + 1;
        check_format(str, nb, &format);
        i = my_check_num_arg(str[*nb]);
        if (i == -1) {
            my_putchar(str[*nb - 1]);
            my_putchar(str[*nb]);
            return;
        }
        tab_func(av, &i, &format);
    }
    else
        my_putchar(str[*nb]);
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list av;
    va_start(av, str);

    while (str[i] != '\0') {
        my_check_mod(str, av, &i);
        i = i + 1;
    }
    va_end(av);
}
