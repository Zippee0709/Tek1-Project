/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** all usefull function who swap
*/

#include "my.h"
#include "sokoban.h"

void my_swap_char(char *a, char *b)
{
    char save = *a;

    if (*a == 'X' && *b == 'O') {
        *b = *a;
        *a = ' ';
    }
    else {
        *a = *b;
        *b = save;
    }
}

void my_swap_o(char *a, char *b)
{
    *b = *a;
    *a = ' ';
}

int my_count_x(char const *str)
{
    int i = 0;
    int nb_x = 0;

    while (str[i] != '\0') {
        if (str[i] == 'X')
            nb_x = nb_x + 1;
        i = i + 1;
    }
    return (nb_x);
}
