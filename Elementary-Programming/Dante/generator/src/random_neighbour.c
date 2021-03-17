/*
** EPITECH PROJECT, 2019
** rand_neighbour.c
** File description:
** random_neighbour
*/

#include "dante.h"

int random_up(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    Pos_t c = *p;

    if (c.y - 2 >= 0) {
        c.y -= 2;
        if (my_check_neighbour(dante, &map[c.y][c.x], &map[c.y + 1][c.x]) == 0)
            return (0);
        *p = c;
        return (1);
    }
    return (0);
}

int random_down(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    Pos_t c = *p;

    if (c.y + 2 < c.max_y) {
        c.y += 2;
        if (my_check_neighbour(dante, &map[c.y][c.x], &map[c.y - 1][c.x]) == 0)
            return (0);
        *p = c;
        return (1);
    }
    return (0);
}

int random_left(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    Pos_t c = *p;

    if (c.x - 2 >= 0) {
        c.x -= 2;
        if (my_check_neighbour(dante, &map[c.y][c.x], &map[c.y][c.x + 1]) == 0)
            return (0);
        *p = c;
        return (1);
    }
    return (0);
}

int random_right(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    Pos_t c = *p;

    if (c.x + 2 < c.max_x) {
        c.x += 2;
        if (my_check_neighbour(dante, &map[c.y][c.x], &map[c.y][c.x - 1]) == 0)
            return (0);
        *p = c;
        return (1);
    }
    return (0);
}

void my_random_neighbour(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    myrand tab[4] = {random_right, random_down, random_left, random_up};

    for (int i = rand() % 3 + 0; i < 4; i++)
        (*tab[i])(dante, map, p);
}
