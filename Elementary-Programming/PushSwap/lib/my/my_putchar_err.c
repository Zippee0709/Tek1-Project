/*
** EPITECH PROJECT, 2018
** my_putchar_err.c
** File description:
** my_putchar function who print on error output
*/

#include "my.h"

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
