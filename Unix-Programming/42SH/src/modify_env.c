/*
** EPITECH PROJECT, 2019
** modify environment
** File description:
** minishell
*/

#include "../include/minishell.h"
#include <string.h>

char *modify_pwd(char *env, char *path)
{
    int i = 4;
    int a = 0;

    free(env);
    env = malloc(sizeof(char) * my_strlen(path) + 5);
    env[0] = 'P';
    env[1] = 'W';
    env[2] = 'D';
    env[3] = '=';
    while (i != my_strlen(path) + 4) {
        env[i] = path[a];
        i = i + 1;
        a = a + 1;
    }
    env[i] = '\0';
    return (env);
}

char *old_pwd(char *env)
{
    env[0] = 'O';
    env[1] = 'L';
    env[2] = 'D';
    env[3] = 'P';
    env[4] = 'W';
    env[5] = 'D';
    env[6] = '=';
    return env;
}

char *modify_old_pwd(char *env, char *path)
{
    int i = 7;
    int a = 0;

    free(env);
    env = malloc(sizeof(char) * my_strlen(path) + 8);
    env = old_pwd(env);
    while (i != my_strlen(path) + 7) {
        env[i] = path[a];
        i = i + 1;
        a = a + 1;
    }
    env[i] = '\0';
    return (env);
}

char **modify_env(char **env, char *path, char *old_path)
{
    int i = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D' &&
            env[i][3] == '=') {
            env[i] = modify_pwd(env[i], path);
        }
        if (strstr(env[i], "OLDPWD=") != NULL)
            env[i] = modify_old_pwd(env[i], old_path);
        i = i + 1;
    }
    return (env);
}
