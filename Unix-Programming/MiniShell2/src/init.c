/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
*/

#include "minishell.h"

int my_init_shell(Shell_t *shell, char **env)
{
    shell->env = NULL;
    shell->env = copy_double_tab_in_list(shell->env, env);
    if (shell->env == NULL) {
        shell->env = NULL;
        return (ERROR);
    }
    shell->cmd = NULL;
    shell->path = NULL;
    shell->str = NULL;
    shell->full_path = NULL;
    shell->env_tab = NULL;
    shell->status = 0;
    return (SUCCESS);
}
