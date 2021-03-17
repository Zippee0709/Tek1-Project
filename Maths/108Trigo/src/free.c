/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "trigo.h"

void my_free_dtab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab[i]);
    free(tab);
}

void my_free_all(Global_t *global)
{
    my_free_dtab(global->tab_type);
    free(global->type);
    free(global->value);
    free(global->result);
}
