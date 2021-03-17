/*
** EPITECH PROJECT, 2019
** check_next.c
** File description:
** check_next.c
*/

#include "dante.h"

int check_next_down(s_map *map, solve *s)
{
    if (s->y < s->ymax && map->map[s->y + 1][s->x] == 'E') {
        map->map[s->ymax][s->xmax] = 'o';
        change_flag(map, s);
        print_map(map->map, s);
        return (1);
    }
    return (0);
}

int check_next_right(s_map *map, solve *s)
{
    if (s->x < s->xmax && map->map[s->y][s->x + 1] == 'E') {
        map->map[s->ymax][s->xmax] = 'o';
        change_flag(map, s);
        print_map(map->map, s);
        return (1);
    }
    return (0);
}
