/*
** EPITECH PROJECT, 2019
** minishell 2
** File description:
** tools
*/

#include "my.h"

char *add_char(char *str, char c)
{
    char *string = malloc(sizeof(char) * my_strlen(str) + 2);
    int i = 0;

    if (string == NULL)
        exit(84);
    while (i != my_strlen(str)) {
        string[i] = str[i];
        i = i + 1;
    }
    string[i] = c;
    string[i + 1] = '\0';
    free(str);
    return (string);
}

int str_contains(char *buf, char *str)
{
    int i = 0;

    while (buf[i] != '\0') {
        if (buf[i] != str[i])
            return (1);
        i = i + 1;
    }
    return (0);
}
