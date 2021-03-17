/*
** EPITECH PROJECT, 2019
** check_shape.c
** File description:
** check_shape.c
*/

#include "my.h"
#include "tetris.h"

int my_check_shape_pos(shape_t shape, int max_x, int max_y, char **map)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < shape.size; i++) {
        for (j = 0; j < shape.size; j++) {
            if (shape.x + j < 0 || shape.x + j >= max_x)
                return (1);
            else if (shape.y + i >= max_y ||
                    map[shape.y + i][shape.x + j] == '*')
                return (2);
        }
    }
    return (0);
}
