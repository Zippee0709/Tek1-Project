/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../my.h"
#include "printf.h"

void tab_func(va_list av, int nb)
{
    int i = 0;
    void (*tab_func[12])(va_list) = {flag_d, flag_d, flag_o, flag_u, flag_x,
                                     flag_X, flag_c, flag_s, flag_S, flag_p,
                                     flag_b, flag_mod};

    while (i != nb)
        i = i + 1;
    (*tab_func[i])(av);
}

int my_check_num_flag(char letter)
{
    int i = 0;
    char *str = "diouxXcsSpb%";

    while (str[i] != '\0') {
        if (str[i] == letter)
            return (i);
        i = i + 1;
    }
    return (0);
}

int my_check_flag(char letter)
{
    int i = 0;
    char *str = "diouxXcsSpb%";
    
    while (str[i] != '\0') {
        if (str[i] == letter)
            return (1);
        i = i + 1;
    }
    return (0);
}

int my_check_mod(char a, char b, va_list av, int *nb)
{
    int i = 0;

    if (a == '%' && my_check_flag(b) == 1) {
        i = my_check_num_flag(b);
        tab_func(av, i);
        *nb = *nb + 1;
    }
    else
        my_putchar(a);
}

int my_printf(char *str, ...)
{
    int i = 0;
    int nb = 0;
    va_list av;
    va_start(av, str);

    while (str[i] != '\0') {
        my_check_mod(str[i], str[i + 1], av, &i);
        i = i + 1;
    }
    va_end(av);
}
