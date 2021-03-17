/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get.c
*/

#include "dante.h"

int my_get_nb_unvisited_cell(Cell_t **map, Pos_t pos)
{
    int nb = 0;

    for (int i = 0; i < pos.max_y; i += 2) {
        for (int j = 0; j < pos.max_x; j += 2) {
            if (map[i][j].visited == FALSE)
                nb++;
        }
    }
    return (nb);
}

int my_get_wall_in_map(Cell_t **map, Pos_t pos)
{
    int nb = 0;

    for (int i = 0; i < pos.max_y; i++) {
        for (int j = 0; j < pos.max_x; j++) {
            if (map[i][j].c == 'X')
                nb++;
        }
    }
    return (nb);
}

int my_get_success_road_hor(Cell_t **map, int max_x, int y)
{
    int x = 0;
    int road = 0;

    for (x = 0; x < max_x - 1; x++) {
        if (map[y][x].c == '*')
            road++;
        else
            road = 0;
    }
    return (road);
}

int my_get_success_road_ver(Cell_t **map, int max_x, int y)
{
    int x = 0;
    int road = 0;

    for (x = 0; x < max_x - 1; x++) {
        if (map[x][y].c == '*')
            road++;
        else
            road = 0;
    }
    return (road);
}
