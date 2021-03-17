/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** all check func
*/

#include "my.h"
#include "minishell.h"

static int my_check_builtins_next(Shell_t *shell, char **cmd, int *quit)
{
    int status = 0;

    if (my_strcmp(cmd[0], "setenv") == 0) {
        my_setenv(shell, cmd[1], cmd[2]);
        return (1);
    }
    if (my_strcmp(cmd[0], "cd") == 0) {
        status = my_check_directory(shell, cmd);
        return (status);
    }
    if (my_strcmp(cmd[0], "exit") == 0) {
        if (cmd[1] != NULL)
            *quit = my_getnbr(cmd[1]);
        return (-1);
    }
    return (0);
}

static int my_check_builtins(Shell_t *shell, char **cmd, int *quit)
{
    int status = 0;

    if (my_strcmp(cmd[0], "env") == 0) {
        if (cmd[1] == NULL)
            print_list(shell->env);
        return (1);
    }
    if (my_strcmp(cmd[0], "unsetenv") == 0) {
        my_unsetenv(shell, cmd[1]);
        return (1);
    }
    status = my_check_builtins_next(shell, cmd, quit);
    return (status);
}

int check_cmd(Shell_t *shell)
{
    int status = 0;
    DlistElement *tmp;

    if (shell->cmd == NULL)
        return (-1);
    tmp = shell->cmd->begin;
    while (tmp != NULL) {
        status = my_check_builtins(shell, tmp->cmd, &shell->status);
        if (status == -1)
            return (-1);
        if (status == 0) {
            if (check_access(shell, tmp->cmd) == 84)
                return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}
