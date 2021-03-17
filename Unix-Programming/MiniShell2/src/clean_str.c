/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** clean_str.c
*/

#include "minishell.h"

static char *my_clean_space(char *str)
{
    int i = 0;
    int j = my_strlen(str);
    int k = 0;

    for (; str[i] != '\0' && str[i] == ' '; i++);
    for (; j > 0 && str[j - 1] == ' '; j--);
    for (k = 0; i < j; k++, i++)
        str[k] = str[i];
    str[k] = '\0';
    return (str);
}

static char *my_clean_pipe_dot(char *str, char *cpy, int *i, int *j)
{
    if (str[*i] == ';' || str[*i] == '|') {
        cpy[*j] = str[*i];
        for (; str[*i + 1] == ' ' || str[*i + 1] == '\t' ||
                str[*i + 1] == ';' || str[*i + 1] == '|'; *i = *i + 1);
        if (str[*i + 1] == '\0')
            cpy[*j] = '\0';
    }
    return (cpy);
}

static char *my_clean_s(char *str)
{
    int j = 0;
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (cpy == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i] == '\t') {
            cpy[j] = ' ';
            for (; str[i + 1] == ' ' || str[i + 1] == '\t'; i++);
        } else
            cpy[j] = str[i];
        cpy = my_clean_pipe_dot(str, cpy, &i, &j);
    }
    cpy[j] = '\0';
    free(str);
    return (cpy);
}

char *clean_str(char *str)
{
    char *copy = NULL;

    if (str == NULL)
        return (NULL);
    str = my_clean_space(str);
    copy = my_clean_s(str);
    copy = my_clean_space(copy);
    return (copy);
}
