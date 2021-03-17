/*
** EPITECH PROJECT, 2019
** my_strspecialcpy.c
** File description:
** special_cpy searching path
*/

#include "minishell.h"

char *my_strcpy_until(char *dest, char const *src, char chr)
{
    int i = 0;
    int dst = 0;

    while (src[i] != '\0' && src[i] != chr) {
        if (src[i] != '\t') {
            dest[dst] = src[i];
            dst++;
        }
        i++;
    }
    dest[dst] = '\0';
    return dest;
}

int my_strlen_until(char *str, char chr)
{
    int i = 0;
    int count = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0' && str[i] != chr) {
        if (str[i] != '\t')
            count++;
        i++;
    }
    return count;
}

int my_other_strlen(char const *str, int i)
{
    int res = 0;

    while (str[i] != ':' && str[i] != '\0') {
        i++;
        res++;
    }
    return (res);
}

char *separate(char *path, char const *src, int *start, int *i)
{
    while (src[*start] != '\0' && src[*start] != ':') {
        path[*i] = src[*start];
        *start = *start + 1;
        *i = *i + 1;
    }
    return path;
}

char *strcpy_after(char *dest, char const *src, int *start)
{
    int i = 0;
    char *path = NULL;

    if (src == NULL)
        return NULL;
    while (src[*start] != '\0' && src[*start] != '/')
        *start = *start + 1;
    path = malloc(sizeof(char) * (my_other_strlen(src, *start) + 2));
    if (path == NULL)
        return NULL;
    path = separate(path, src, start, &i);
    if (i == 0)
        return NULL;
    path[i] = '/';
    path[i + 1] = '\0';
    dest = my_strcat(path, dest);
    free(path);
    return dest;
}
