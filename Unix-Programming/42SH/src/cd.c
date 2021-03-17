/*
** EPITECH PROJECT, 2019
** builtins cd
** File description:
** minishell
*/

#include "../include/minishell.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int calc_arg(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i = i + 1;
    return (i);
}

char **find_home(char **env, char *old_pwd)
{
    int i = 0;
    char *path;

    while (env[i] != NULL) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E' && env[i][4] == '=') {
            path = malloc(sizeof(char) * my_strlen(env[i]) + 1);
            path = my_strcpy(path, env[i]);
            if (path != NULL)
                env = modify_env(env, &path[5], old_pwd);
            if (chdir(&path[5]) == -1)
                my_printf("%s: No such file or directory.\n", &path[5]);
            return (env);
        }
        i = i + 1;
    }
    return (env);
}

char *check_access(char **arr)
{
    size_t size = 0;
    char * old_pwd = NULL;
    char *path = NULL;

    while (getcwd(old_pwd, size) == NULL)
        size = size + 1;
    old_pwd = getcwd(old_pwd, size);
    if (chdir(arr[1]) == -1) {
        my_printf("%s: Not a directory.\n", arr[1]);
        return (NULL);
    }
    for (size = 0; getcwd(NULL, size) == NULL; size = size + 1);
    path = getcwd(path, size);
    return (path);
}

char *get_old_pwd(char **env)
{
    int y = 0;

    while (env[y] != NULL) {
        if (strstr(env[y], "OLDPWD=") != NULL)
            return &env[y][7];
        y++;
    }
    return NULL;
}

char **do_command(char *buf, char **env)
{
    char **arr = my_str_to_word_array(buf, ' ');
    char *path;
    char *old_pwd = NULL;

    for (size_t size = 0; (old_pwd = getcwd(NULL, size)) == NULL;
    size = size + 1);
    if (calc_arg(arr) > 2)
        toomuch_arg(arr);
    if (arr[1] == NULL) {
        env = find_home(env, old_pwd);
    } else if (arr[1][0] == '-') {
        if (chdir(get_old_pwd(env)) == -1)
            my_printf("%s: No such file or directory.\n", old_pwd);
    } else {
        path = check_access(arr);
        if (path != NULL)
            env = modify_env(env, path, old_pwd);
    }
    free_dtab(arr);
    return (env);
}
