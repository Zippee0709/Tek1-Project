/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** reproduce the behavior of the my_strstr function
*/
#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != to_find[j]) {
        if (str[i] == '\0')
            return (NULL);
        i = i + 1;
    }
    while (str[i] != '\0' && to_find[j] != '\0') {
        if (to_find[j] == str[i])
            str[k] = to_find[j];
        i = i + 1;
        j = j + 1;
        k = k + 1;
    }
    str[k] = '\0';
    return (str);
}
