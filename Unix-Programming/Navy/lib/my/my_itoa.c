/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** itoa
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char swap;

    while (j > i) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        j = j - 1;
        i = i + 1;
    }
    return (str);
}

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    int mod = 0;
    int i = 0;

    *str = '\0';
    my_revstr(str);
    while (nb != 0) {
        mod = nb % 10;
        str[i] = (mod > 9) ? (mod - 10) + 'a' : mod + '0';
        i++;
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
