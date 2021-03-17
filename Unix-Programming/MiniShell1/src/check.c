/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** all check func
*/

#include "my.h"
#include "minishell.h"

int my_check_builtins(char **env, char **cmd)
{
    if (my_strcmp(cmd[0], "env") == 0) {
        if (cmd[1] == NULL)
            my_show_word_array(env);
        return (1);
    }
    /* if (my_strcmp(cmd[0], "setenv") == 0) { */
    /*     my_set_env(env, line); */
    /*     return (1); */
    /* } */
    /* if (my_strcmp(cmd[0], "unsetenv") == 0) { */
    /*     my_unset_env(env, cmd); */
    /*     return (1); */
    /* } */
    if (my_strcmp(cmd[0], "exit") == 0)
        exit(SUCCESS);
    return (0);
}

void my_check_access(s_shell *shell)
{
    int i = 0;
    pid_t pid = fork();
    
    while (shell->path[i] != NULL) {
        shell->full_path = my_str_concat(shell->path[i], shell->cmd[0]);
        if (access(shell->full_path, F_OK) == 0) {
            if (access(shell->full_path, X_OK) == 0)
                my_execution(shell, shell->full_path, pid);
        }
        free(shell->full_path);
        i = i + 1;
    }
}

int my_check_cmd(s_shell *shell)
{
    int i = 0;
    int status = 0;

    while (shell->cmd[i] != NULL) {
        status = my_check_builtins(shell->env, shell->cmd);
        if (status == 84)
            return (84);
        if (status == 0)
            my_check_access(shell);
        i = i + 1;
    }
    return (0);
}

void my_check_status(int status)
{
    if (status == 84)
        exit(EXIT_ERROR);
}

void my_check_string(char *str)
{
    if (str == NULL)
        exit(SUCCESS);
}
