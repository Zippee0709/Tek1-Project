/*
** EPITECH PROJECT, 2019
** execution.c
** File description:
** execution func
*/

#include "my.h"
#include "minishell.h"

void my_execution(s_shell *shell, char *full_path, pid_t pid)
{
    int status = 0;

    if (pid == -1) {
        my_putstr_err("Error : fork failed !\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        if (execve(full_path, shell->cmd, shell->env) == -1)
            my_printf("Error : execution failed\n");
    }
    else
        waitpid(pid, &status, WUNTRACED);
}
