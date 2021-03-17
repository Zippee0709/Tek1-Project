/*
** EPITECH PROJECT, 2019
** init_direction.c
** File description:
** init_direction
*/

#include "dante.h"

void my_init_pos(Pos_t *pos, int max_x, int max_y)
{
    pos->x = 0;
    pos->y = 0;
    pos->max_x = max_x;
    pos->max_y = max_y;
}
