/*
** EPITECH PROJECT, 2019
** free.C
** File description:
** free function
*/

#include "my.h"
#include "minishell.h"

void my_free_dtab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab[i]);
    free(tab);
}

void my_free_all(s_shell *shell)
{
    free(shell->s);
    my_free_dtab(shell->cmd);
    my_free_dtab(shell->env);
    my_free_dtab(shell->path);
}
