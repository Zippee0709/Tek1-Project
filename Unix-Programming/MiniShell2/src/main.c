/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "minishell.h"

static void my_help(void)
{
    my_putstr("USAGE\n\t\t./minishell\n");
}

int main(int ac, char **av, char **env)
{
    Shell_t shell;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help();
        return (0);
    }
    my_init_shell(&shell, env);
    while (minishell(&shell) != -1);
    free_list(shell.env);
    return (shell.status);
}
