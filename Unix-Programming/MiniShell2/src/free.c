/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "minishell.h"

void my_free_dtab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab[i]);
    free(tab);
}

void my_free_shell(Shell_t *shell)
{
    free(shell->str);
    free_list_cmd(shell->cmd);
}
