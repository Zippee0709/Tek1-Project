/*
** EPITECH PROJECT, 2019
** print.c
** File description:
** print.c
*/

#include "dante.h"

void my_print_map(Cell_t **map, Pos_t pos)
{
    for (int i = 0; i < pos.max_y; i++) {
        for (int j = 0; j < pos.max_x; j++) {
            printf("%c", map[i][j].c);
        }
        if (i < pos.max_y - 1)
            printf("\n");
    }
}
