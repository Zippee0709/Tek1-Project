/*
** EPITECH PROJECT, 2019
** pos_max.c
** File description:
** pos_max.c
*/

#include "dante.h"

void pos_max(solve *s, s_map *map)
{
    int x;
    int y = 0;

    s->x = 0;
    s->y = 0;
    for (x = 0; map->map[y][x] != '\0'; x++);
    s->xmax = x - 1;
    for (y = 0; map->map[y] != NULL; y++);
    s->ymax = y - 1;
    map->map[s->ymax][s->xmax] = 'E';
}
