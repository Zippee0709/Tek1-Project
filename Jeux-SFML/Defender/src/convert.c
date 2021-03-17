/*
** EPITECH PROJECT, 2019
** convert.c
** File description:
** convert.c
*/

#include "my_defender.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_count_nb(int nb)
{
    int i = 1;
    int size = 0;

    if (nb == 0)
        return (1);
    while (nb / i > 0) {
        size = size + 1;
        i = i * 10;
    }
    return (size);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c;

    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    str[i + j + 1] = '\0';
    return (str);
}

char *my_int_convert_str(int nb)
{
    int j = 0;
    int size = my_count_nb(nb);
    char *str = malloc(sizeof(char) * (size + 1));

    if (nb == 0) {
        str[j] = nb + '0';
        str[j + 1] = '\0';
        return (str);
    }
    while (nb > 0) {
        str[j] = (nb % 10) + '0';
        nb = nb / 10;
        j++;
    }
    str[j] = '\0';
    my_revstr(str);
    return (str);
}
