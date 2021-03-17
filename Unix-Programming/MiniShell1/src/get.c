/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get function
*/

#include "my.h"
#include "minishell.h"

int my_get_path_size(char *path)
{
    int i = 0;

    while (path[i] != '\0')
        i = i + 1;
    return (i - 5);
}

char *my_str_del_path(char *str, int size)
{
    int i = my_strlen(str) - size;
    char *cpy = malloc(sizeof(char) * (i + 1));

    if (cpy == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        exit(EXIT_ERROR);
    }
    i = 0;
    while (str[size] != '\0') {
        cpy[i] = str[size];
        size = size + 1;
        i = i + 1;
    }
    cpy[i] = '\0';
    free(str);
    return (cpy);
}

char **my_get_path(char **env)
{
    int i = 0;
    char **path;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H') {
            path = my_str_to_word_tab(env[i], ':');
        }
        i = i + 1;
    }
    path[0] = my_str_del_path(path[0], 5);
    return (path);
}
