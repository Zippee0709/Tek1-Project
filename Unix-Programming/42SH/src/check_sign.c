/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** binary tree
*/

#include "../include/minishell.h"

char **treat_sign(char *buf, char **env)
{
    char **arr = my_str_to_word_array(buf, ';');
    int i = 0;

    while (arr[i] != NULL) {
        arr[i] = clean_buf(arr[i]);
        if (my_strcmp(arr[i], "exit") == 0) {
            my_putstr("exit\n");
            exit(0);
        }
        treat_path(arr[i], env);
        i = i + 1;
    }
    return (env);
}

int check_sign(char *buf)
{
    char **arr = my_str_to_word_array(buf, ';');

    if (arr[1] == NULL) {
        free(arr);
        return (1);
    }
    free(arr);
    return (0);
}
