/*
** EPITECH PROJECT, 2019
** algo
** File description:
** algo
*/

#include "dante.h"

static int find_up(s_map *map, solve *s, int i)
{
    if (s->y > 0 && i == 0)
        if (map->map[s->y - 1][s->x] == '*') {
            s->y--;
            return (1);
        }
    return (0);
}

static int find_down(s_map *map, solve *s, int i)
{
    if (s->y < s->ymax && i == 0)
        if (map->map[s->y + 1][s->x] == '*') {
            s->y++;
            return (1);
        }
    return (0);
}

static int find_left(s_map *map, solve *s, int i)
{
    if (s->x > 0 && i == 0)
        if (map->map[s->y][s->x - 1] == '*') {
            s->x--;
            return (1);
        }
    return (0);
}

static int find_right(s_map *map, solve *s, int i)
{
    if (s->x < s->xmax && i == 0)
        if (map->map[s->y][s->x + 1] == '*') {
            s->x++;
            return (1);
        }
    return (0);
}

char **find_path(s_map *map, solve *s)
{
    int i = 0;

    map->map[0][0] = 'o';
    while (1) {
        if (check_next_down(map, s) == 1 || check_next_right(map, s) == 1)
            return (0);
        i = i + find_right(map, s, i);
        i = i + find_down(map, s, i);
        i = i + find_left(map, s, i);
        i = i + find_up(map, s, i);
        if (i == 0)
            go_back(map, s);
        map->map[s->y][s->x] = 'o';
        i = 0;
    }
    return (map->map);
}