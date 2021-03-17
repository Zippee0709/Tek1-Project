/*
** EPITECH PROJECT, 2019
** check_star.c
** File description:
** check_star.c
*/

#include "dante.h"

int check_star(s_map *map, solve *s)
{
    if (s->y > 0)
        if (map->map[s->y - 1][s->x] == '*')
            return (1);
    if (s->x > 0)
        if (map->map[s->y][s->x - 1] == '*')
            return (1);
    if (s->y < s->ymax)
        if (map->map[s->y + 1][s->x] == '*')
            return (1);
    if (s->x < s->xmax)
        if (map->map[s->y][s->x + 1] == '*')
            return (1);
    return (0);
}
