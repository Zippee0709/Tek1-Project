/*
** EPITECH PROJECT, 2019
** error gestion
** File description:
** error gestion
*/

#include "lemin.h"

void init_err(Error_t *error)
{
    error->x = 0;
    error->y = 0;
    error->end = 0;
    error->start = 0;
}

int check_map(Global_t global, Error_t *error)
{
    init_err(error);
    while (global.tab[error->y] != NULL) {
        if (my_strcmp(global.tab[error->y], "##start") == 0)
            error->start++;
        else if (my_strcmp(global.tab[error->y], "##end") == 0)
            error->end++;
        error->y++;
    }
    if (error->start != 1 || error->end != 1)
        return (84);
    return (0);
}
