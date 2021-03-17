/*
** EPITECH PROJECT, 2019
** shell.c
** File description:
** shell.c
*/

#include "minishell.h"

static void display_pompt(Dlist_t *list)
{
    (void)list;
    my_putstr("$> ");
}

static int load_shell_cmd(Shell_t *shell)
{
    shell->cmd = NULL;
    shell->path = NULL;
    shell->str = get_next_line(0);
    if (shell->str == NULL) {
        my_putstr("exit\n");
        return (-1);
    }
    shell->str = clean_str(shell->str);
    return (0);
}

int minishell(Shell_t *shell)
{
    int status = 0;

    display_pompt(shell->env);
    if (load_shell_cmd(shell) == -1)
        return (-1);
    if (shell->str != NULL && shell->str[0] != '\0') {
        shell->cmd = split_cmd_in_dlist(shell->cmd, shell->str);
        status = check_cmd(shell);
        if (status == -1) {
            my_free_shell(shell);
            return (-1);
        }
        shell->status = status;
    }
    my_free_shell(shell);
    return (shell->status);
}
