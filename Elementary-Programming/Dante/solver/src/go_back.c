/*
** EPITECH PROJECT, 2019
** go_back.c
** File description:
** go_back.c
*/

#include "dante.h"

static int go_back_up(s_map *map, solve *s, int i)
{
    if (s->y > 0 && i == 0)
        if (map->map[s->y - 1][s->x] == 'o') {
            map->map[s->y][s->x] = '!';
            s->y--;
            return (1);
        }
    return (0);
}

static int go_back_left(s_map *map, solve *s, int i)
{
    if (s->x > 0 && i == 0)
        if (map->map[s->y][s->x - 1] == 'o') {
            map->map[s->y][s->x] = '!';
            s->x--;
            return (1);
        }
    return (0);
}

static int go_back_down(s_map *map, solve *s, int i)
{
    if (s->y < s->ymax && i == 0)
        if (map->map[s->y + 1][s->x] == 'o') {
            map->map[s->y][s->x] = '!';
            s->y++;
            return (1);
        }
    return (0);
}

static int go_back_right(s_map *map, solve *s, int i)
{
    if (s->x < s->xmax && i == 0)
        if (map->map[s->y][s->x + 1] == 'o') {
            map->map[s->y][s->x] = '!';
            s->x++;
            return (1);
        }
    return (0);
}

int go_back(s_map *map, solve *s)
{
    int i = 0;

    while (map->map[s->y][s->x] != '*') {
        i = i + go_back_up(map, s, i);
        i = i + go_back_left(map, s, i);
        i = i + go_back_down(map, s, i);
        i = i + go_back_right(map, s, i);
        i = 0;
        if (check_star(map, s) == 1)
            return (0);
    }
    return (0);
}
