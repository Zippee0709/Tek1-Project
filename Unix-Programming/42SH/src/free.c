/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "../include/minishell.h"

void free_dtab(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
