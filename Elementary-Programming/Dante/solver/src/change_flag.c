/*
** EPITECH PROJECT, 2019
** change_flag.c
** File description:
** change_flag.c
*/

#include "dante.h"

int change_flag(s_map *map, solve *s)
{
    s->x = 0;
    s->y = 0;
    while (map->map[s->y] != NULL) {
        while (map->map[s->y][s->x] != '\0') {
            if (map->map[s->y][s->x] == '!')
                map->map[s->y][s->x] = '*';
            s->x++;
        }
        s->y++;
        s->x = 0;
    }
    return (0);
}

