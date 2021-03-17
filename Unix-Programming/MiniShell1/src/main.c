/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_minishell
*/

#include "my.h"
#include "minishell.h"

static void help(void)
{
    my_printf("USAGE : ./minishell");
}

int main(int ac, char **av, char **env)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    minishell(env);
    return (1);
}
