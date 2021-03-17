/*
** EPITECH PROJECT, 2018
** my_putstr_err.c
** File description:
** write a string who print string on error output
*/

#include "my.h"

int my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i = i + 1;
    }
    return (0);
}
