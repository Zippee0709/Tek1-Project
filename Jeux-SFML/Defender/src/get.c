/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get.c
*/

#include "my_defender.h"

int my_get_lenght(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

int my_get_height(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb++;
        i++;
    }
    return (nb);
}
