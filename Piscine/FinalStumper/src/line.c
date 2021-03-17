/*
** EPITECH PROJECT, 2018
** line.c
** File description:
** all usefull function for rush3
*/

#include "rush3.h"

void my_check_rush1(char *str, int x, int y)
{
    if (str[0] == 'o' && str[x - 1] == 'o') {
        my_putstr("[rush1-1] ");
        my_print(x, y);
        my_putchar('\n');
    }
}

void my_check_rush2(char *str, int x, int y)
{
    if ((str[0] == '/' && str[x - 1] == '\\') ||
        (str[0] == '*' && str[x - 1] == '*')) {
        my_putstr("[rush1-2] ");
        my_print(x, y);
        my_putchar('\n');
    }
}

void my_check_rush3(char *str, int x, int y)
{
    if (str[0] == 'A' && str[x - 1] == 'A') {
        my_putstr("[rush1-3] ");
        my_print(x, y);
        my_putchar('\n');
    }
    else if (str[0] == 'B' && str[x - 1] == 'B') {
        my_putstr("[rush1-3] ");
        my_print(x, y);
        my_putstr(" || ");
    }
}

void my_check_rush4(char *str, int x, int y, int i)
{
    if (str[0] == 'A' && str[i - 2] == 'C') {
        my_putstr("[rush1-4] ");
        my_print(x, y);
        my_putchar('\n');
    }
    else if (str[0] == 'B' && str[x - 1] == 'B') {
        my_putstr("[rush1-4] ");
        my_print (x, y);
        my_putstr(" || ");
    }
}

void my_check_rush5(char *str, int x, int y, int i)
{
    if (str[0] == 'A' && str[i - 2] == 'A') {
        my_putstr("[rush1-5] ");
        my_print(x, y);
        my_putchar('\n');
    }
    else if (str[0] == 'B' && str[x - 1] == 'B') {
        my_putstr("[rush1-5] ");
        my_print(x, y);
        my_putchar('\n');
    }
}
