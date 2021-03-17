/*
** EPITECH PROJECT, 2019
** func.c
** File description:
** func.c
*/

#include "bombyx.h"

int my_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (84);
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i++;
    }
}
