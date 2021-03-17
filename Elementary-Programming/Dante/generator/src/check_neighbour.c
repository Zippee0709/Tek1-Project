/*
** EPITECH PROJECT, 2019
** check_neighbour.c
** File description:
** check_neighbour.c
*/

#include "dante.h"

int check_up(Pos_t p, Cell_t **map, int nb)
{
    if ((p.y - 2 >= 0 && map[p.y - 2][p.x].visited == FALSE))
        nb++;
    return (nb);
}

int check_down(Pos_t p, Cell_t **map, int nb)
{
    if ((p.y + 2 < p.max_y && map[p.y + 2][p.x].visited == FALSE))
        nb++;
    return (nb);
}

int check_left(Pos_t p, Cell_t **map, int nb)
{
    if ((p.x - 2 >= 0 && map[p.y][p.x - 2].visited == FALSE))
        nb++;
    return (nb);
}

int check_right(Pos_t p, Cell_t **map, int nb)
{
    if ((p.x + 2 < p.max_x && map[p.y][p.x + 2].visited == FALSE))
        nb++;
    return (nb);
}

int my_check_neighbour_avaible(Dante_t *dante)
{
    Cell_t **map = dante->map;
    Pos_t p = dante->pos;
    int nb = 0;
    neighbour tab[4] = {check_up, check_down, check_left, check_right};

    for (int i = 0; i < 4; i++)
        nb = (*tab[i])(p, map, nb);
    return (nb);
}
