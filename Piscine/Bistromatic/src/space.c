/*
** EPITECH PROJECT, 2018
** space.c
** File description:
** all usefull function about space
*/

#include "bistromatic.h"
#include "my.h"

int my_strlen_no_space(char const *str)
{
    int i = 0;
    int nb_space = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '-')
            nb_space = nb_space + 1;
        i = i + 1;
    }
    i = i - nb_space;
    return (i);
}
