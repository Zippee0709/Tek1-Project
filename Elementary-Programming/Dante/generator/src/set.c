/*
** EPITECH PROJECT, 2019
** set.c
** File description:
** set.c
*/

#include "dante.h"

void my_set_road_in_map(Cell_t *map)
{
    map->c = '*';
    map->visited = TRUE;
}

void my_set_wall_in_map(Cell_t *map)
{
    map->c = 'X';
    map->visited = TRUE;
}

void my_set_exit_cell(Cell_t **map, Pos_t *p)
{
    if (my_check_is_wall(map, p->max_x - 1, p->max_y - 1) == 1) {
        if (my_check_is_wall(map, p->max_x - 1, p->max_y - 2) == 1 &&
            my_check_is_wall(map, p->max_x - 2, p->max_y - 1) == 1)
            map[p->max_y - 1][p->max_x - 2].c = '*';
        else if (my_check_is_wall(map, p->max_x - 1, p->max_y - 2) == 0 &&
                my_check_is_wall(map, p->max_x - 2, p->max_y - 1) == 0)
            map[p->max_y - 2][p->max_x - 1].c = 'X';
        map[p->max_y - 1][p->max_x - 1].c = '*';
    }
}
