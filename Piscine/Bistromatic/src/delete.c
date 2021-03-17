/*
** EPITECH PROJECT, 2018
** delete.c
** File description:
** all usefull function who delete or free something
*/

#include "bistromatic.h"
#include "my.h"

char *my_strcpy_i(char *str, int *i, char *copy)
{
    int j = 0;

    if (copy[j] == '-')
        j = j + 1;
    while (str[*i] != '\0') {
        copy[j] = str[*i];
        *i = *i + 1;
        j = j + 1;
    }
    copy[j] = '\0';
    return (copy);
}

char *my_delete_zero(char *str)
{
    int i = 0;
    char *copy = malloc(sizeof(char) * my_strlen(str + 1));

    if (str[i] == '-') {
        copy[0] = '-';
        i = i + 1;
    }
    while (str[i] == '0') {
        if (str[i] == '0' && str[i + 1] == '\0') {
            copy[0] = '0';
            copy[1] = '\0';
            return (copy);
        }
        i = i + 1;
    }
    copy = my_strcpy_i(str, &i , copy);
    return (copy);
}
