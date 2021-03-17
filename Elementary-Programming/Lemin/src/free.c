/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "lemin.h"
#include "my.h"

void my_free_dtab(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void my_free_int_dtab(int **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_list(DlistAnts *ants)
{
    DlistAnts *tmp = NULL;

    while (ants != NULL) {
        tmp = ants;
        ants = ants->next;
        free(tmp);
    }
}

void my_free_all(Global_t *global)
{
    my_free_dtab(global->tab);
    my_free_dtab(global->rooms);
    my_free_dtab(global->tunnels);
    my_free_int_dtab(global->previous);
    my_free_int_dtab(global->status);
    free_list(global->ants);
    free(global->file);
    free_graph(global->graph);
    free_graph(global->close);
}
