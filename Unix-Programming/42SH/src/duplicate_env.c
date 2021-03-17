/*
** EPITECH PROJECT, 2019
** duplicate environment
** File description:
** minishell
*/

#include "../include/minishell.h"

char **fill_env(char **env, char **envi)
{
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        j = 0;
        while (env[i][j] != '\0') {
            envi[i][j] = env[i][j];
            j = j + 1;
        }
        envi[i][j] = '\0';
        i = i + 1;
    }
    envi[i] = NULL;
    return (envi);
}

char **duplicate_env(char **env)
{
    int i = 0;
    int j = 0;
    char **envi = NULL;

    while (env[i] != NULL)
        i = i + 1;
    envi = malloc(sizeof(char *) * (i + 1));
    if (envi == NULL)
        exit(0);
    i = 0;
    while (env[i] != NULL) {
        j = 0;
        while (env[i][j] != '\0')
            j = j + 1;
        envi[i] = malloc(sizeof(char) * j + 1);
        if (envi[i] == NULL)
            exit(0);
        i = i + 1;
    }
    return (fill_env(env, envi));
}
