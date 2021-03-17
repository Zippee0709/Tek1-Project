/*
** EPITECH PROJECT, 2019
** func.c
** File description:
** func.c
*/

#include "my.h"
#include "minishell.h"

int my_strcmp_begin(char *s1, char *s2)
{
    int i = 0;

    while (s2[i] != '\0') {
        if (s2[i] != s1[i])
            return (1);
        i++;
    }
    return (0);
}

char *my_str_char_cpy(char *dest, char *src, char c, int i)
{
    int j = 0;

    while (src[i] != '\0' && src[i] != c) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char *my_clean_str(char *str, char c)
{
    int i = 0;
    char *cpy;

    if (str == NULL)
        return (NULL);
    while (str[i] != c && str[i] != '\0')
        i++;
    cpy = malloc(sizeof(char) * (i + 1));
    i = 0;
    cpy = my_str_char_cpy(cpy, str, c, i);
    free(str);
    return (cpy);
}

char *my_clean_pwd(char *str, char c)
{
    int i = 0;
    int size = 0;
    char *cpy;

    if (str == NULL)
        return (NULL);
    i = my_strlen(str);
    while (str[i] != c && i != 0) {
        size++;
        i--;
    }
    i++;
    cpy = malloc(sizeof(char) * (size + 1));
    cpy = my_str_char_cpy(cpy, str, c, i);
    free(str);
    return (cpy);
}

char *my_clean_path(char *str, char c)
{
    int i = 0;
    int size = 0;
    char *cpy = NULL;

    if (str == NULL)
        return (NULL);
    size = my_strlen(str);
    while (size > 0 && str[size] != c)
        size--;
    cpy = malloc(sizeof(char) * (size + 1));
    while (i < size) {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}
