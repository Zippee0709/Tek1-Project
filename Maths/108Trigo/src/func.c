/*
** EPITECH PROJECT, 2019
** func.c
** File description:
** my_putstr_err.c
*/

#include "trigo.h"

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr_err(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i++;
    }
}
