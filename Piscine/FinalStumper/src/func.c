/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull function
*/

#include <unistd.h>
#include "rush3.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i = i + 1;
    }
}

int my_check_char_if_b(char *str)
{
    if (str[0] == 'B') {
        my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1\n");
        return (1);
    }
    return (0);
}
