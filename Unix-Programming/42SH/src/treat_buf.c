/*
** EPITECH PROJECT, 2019
** treat buf
** File description:
** minishell
*/

#include "../include/minishell.h"

void do_fork(char **array, char *path, char **env)
{
    pid_t pid = 0;
    int status = 0;
    redirect_s redirect = {NULL, 0, NULL, NULL, -1};

    if ((pid = fork()) == 0) {
        redirect.pid = pid;
        array = do_redirect(array, &redirect);
        execve(path, array, env);
        exit(0);
    } else {
        waitpid(pid, &status, WIFSIGNALED(status));
        status = check_segfault(status, pid);
    }
}

char *find_path(char *file, char **env)
{
    int col = 0;
    int start = 0;
    char *path = NULL;

    while (env[col] != NULL) {
        if (env[col][0] == 'P' && env[col][1] == 'A' &&
            env[col][2] == 'T' && env[col][3] == 'H' &&
            env[col][4] == '=')
            break;
        col++;
    }
    do {
        path = strcpy_after(file, env[col], &start);
        if (path == NULL || access(path, X_OK) != -1)
            break;
    } while (path != NULL);
    if (path == NULL)
        return not_dev(file);
    return (path);
}

void treat_path(char *buf, char **env)
{
    char **array = my_str_to_word_array(buf, ' ');
    char *pathname = NULL;
    redirect_s redirect = {NULL, 0, NULL, NULL, -1};

    if (check_redirect(array[0]) != NO_REDIRECT) {
        do_redirect(array, &redirect);
        return;
    }
    pathname = find_path(array[0], env);
    if (pathname != NULL && array != NULL)
        do_fork(array, pathname, env);
    free(array);
}

char **treat_buf(char *buf, char **env)
{
    if (check_sign(buf) == 0) {
        env = treat_sign(buf, env);
    } else {
        if (str_contains("cd", buf) == 0)
            return (do_command(buf, env));
        else if (my_strcmp(buf, "setenv") == 0 || my_strcmp(buf, "env") == 0)
            return (print_env(env));
        if (str_contains("setenv", buf) == 0)
            return (do_setenv(my_str_to_word_array(buf, ' '), env));
        else if (str_contains("unsetenv", buf) == 0)
            return (delete_env(env, buf));
        else
            treat_path(buf, env);
    }
    return (env);
}
