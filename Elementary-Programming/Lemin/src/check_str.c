/*
** EPITECH PROJECT, 2019
** check_str.c
** File description:
** check_str.c
*/

#include "lemin.h"
#include "my.h"

int my_check_str_is_tunnel(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
            i++;
        else
            return (1);
    }
    if (i != 3)
        return (1);
    return (0);
}

int my_check_str_only_nbr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == ' ')
            i++;
        else
            return (1);
    }
    if (i < 5)
        return (1);
    return (0);
}
