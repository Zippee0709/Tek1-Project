/*
** EPITECH PROJECT, 2019
** minishell 2
** File description:
** unsetenv builtin
*/

#include "../include/minishell.h"

static char **unset_env(char **env, char *buf)
{
    int size = 0;
    int a = 0;
    char **envi;
    char **check;

    for (; env[size]; size++);
    envi = malloc(sizeof(char *) * size);
    for (int i = 0; env[i] != NULL; i++) {
        check = my_str_to_word_array(env[i], '=');
        if (my_strcmp(check[0], buf) == 0);
        else {
            envi[a] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
            envi[a] = my_strcpy(envi[a], env[i]);
            a = a + 1;
        }
        free(check);
    }
    envi[a] = NULL;
    free(env);
    return (envi);
}

static int check_env(char **env, char *buf)
{
    int i = 0;
    char **check;

    while (env[i] != NULL) {
        check = my_str_to_word_array(env[i], '=');
        if (my_strcmp(check[0], buf) == 0)
            return (0);
        i = i + 1;
    }
    return (1);
}

char **delete_env(char **env, char *buf)
{
    char **check = my_str_to_word_array(buf, ' ');
    int i = 0;
    int a = 1;

    for (; check[i]; i++);
    if (i == 1)
        notenough_arg(check[0]);
    else {
        while (check[a] != NULL) {
            if (check_env(env, check[a]) == 0)
                env = unset_env(env, check[a]);
            a = a + 1;
        }
    }
    free(check);
    return (env);
}
