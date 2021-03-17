/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac != 1)
        return (84);
    else
        start_shell(duplicate_env(env));
    return (0);
}
