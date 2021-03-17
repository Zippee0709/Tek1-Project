/*
** EPITECH PROJECT, 2018
** tools for files
** File description:
** putstr getnbr
*/

#include "my.h"

int my_strcmp(char const *s, char const *t)
{
    int a = my_strlen(s);
    int b = my_strlen(t);
    int i = 0;

    if (a != b)
        return (1);
    while (i != a) {
        if (s[i] != t[i])
            return (1);
        i = i + 1;
    }
    return (0);
}

char *concat_params(char *argv, char *argv2, char c)
{
    int size = my_strlen(argv) + my_strlen(argv2) + 2;
    char *str = malloc(sizeof(char) * size);
    int a = 0;
    int i = 0;

    if (str == NULL)
        exit(84);
    while (argv[i] != '\0') {
        str[i] = argv[i];
        i = i + 1;
    }
    str[i] = c;
    i = i + 1;
    while (argv2[a] != '\0') {
        str[i] = argv2[a];
        a = a + 1;
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}

int is_targ(char *target, char *line)
{
    int i = 0;

    for (; line[i] && target[i] && line[i] != '='; i++)
        if (line[i] != target[i])
            return (1);
    if (line[i] == '=' && target[i] == '\0')
        return (0);
    return (1);
}