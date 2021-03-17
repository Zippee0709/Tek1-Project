/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "dante.h"

void my_free_map(Cell_t **map, Pos_t pos)
{
    int i = 0;

    for (i = 0; i < pos.max_y; i++) {
        free(map[i]);
    }
    free(map);
}

void my_free_dlist(Dlist_t *list)
{
    while (list != NULL)
        list = pop_begin_list(list);
}
