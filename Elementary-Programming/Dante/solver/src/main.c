/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for
*/

#include "dante.h"

void print_map(char **map, solve *s)
{
    for (int p  = 0; map[p] != map[s->ymax]; p++)
        printf("%s\n", map[p]);
    printf("%s", map[s->ymax]);
}

int main(int ac, char **av)
{
    solve *s = malloc(sizeof(*s));
    s_map *map = malloc(sizeof(*map));

    if (ac != 2)
        return (84);
    alloc_map(av[1], map);
    pos_max(s, map);
    map->map = find_path(map, s);
    return (0);
}
