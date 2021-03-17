/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** lib.c
*/

#include "my_rpg.h"

int mstrlen(char const *str, int a)
{
    return ((str[a]) ? (mstrlen(str, a + 1)) : a);
}

int get_nbr(char const *s)
{
    int nb = 0;

    if (!s)
        return (FAILURE);
    for (int i = (s[0] == '-') ? 1 : 0; s[i] >= '0' && s[i] <= '9'; i++)
        nb = nb * 10 + s[i] - 48;
    return (s[0] == '-') ? (-nb) : (nb);
}

char *str_cat(char *s1, char *s2)
{
    int a = 0;
    int b = 0;
    char *tmp = NULL;

    for (; s1 && s1[a]; a++);
    for (; s2 && s2[b]; b++);
    tmp = malloc(a + b + 1);
    if (!tmp)
        return (NULL);
    tmp[a + b] = '\0';
    for (int c = 0; s1 && c ^ a; c++)
        tmp[c] = s1[c];
    for (int c = 0; s2 && c ^ b; c++)
        tmp[a + c] = s2[c];
    return (tmp);
}

FILE *open_file(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");

    return (!fd) ? open_file(filepath) : fd;
}

char *read_file(char const *filepath)
{
    FILE *fd = open_file(filepath);
    size_t size = 0;
    char *file = NULL;
    char *buf = NULL;

    do {
        file = str_cat(file, buf);
        size = getline(&buf, &size, fd);
    } while (size != EOF);
    fclose(fd);
    return (file);
}
