/*
** EPITECH PROJECT, 2019
** print_tetris.c
** File description:
** print_tetris.c
*/

#include "tetris.h"
#include "my.h"

void my_write_shape_in_map(shape_t current, char **map)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < current.size; i++) {
        for (j = 0; j < current.size; j++) {
            if (current.shape[i][j] == '1')
                map[current.y + i][current.x + j] = '*';
        }
    }
}

char **my_strcpy_tab(char **str1, char **str2)
{
    int i = 0;
    int j = 0;

    for (i = 0; str2[i] != NULL; i++) {
        for (j = 0; str2[i][j] != '\0'; j++)
            str1[i][j] = str2[i][j];
    }
    return (str1);
}

void my_rotate_shape(shape_t *shape)
{
    shape_t tmp = my_copy_shape(*shape);
    int i = 0;
    int j = 0;
    int k = 0;
    int size = 0;
    size = shape->size;
    for (i = 0; i < size; i++) {
        for (j = 0, k = size - 1; j < size; j++, k--)
            shape->shape[i][j] = tmp.shape[k][i];
    }
}

void my_print_shape(shape_t shape)
{
    int i = 0;

    for (i = 0; i < shape.size; i++)
        printw("%s\n", shape.shape[i]);
}

void my_print_game_map(char **map, int x)
{
    int i = 0;

    printw("+");
    for (i = 0; i < x; i++)
        printw("-");
    printw("+\n");
    for (i = 0; map[i] != NULL; i++)
        printw("|%s|\n", map[i]);
    printw("+");
    for (i = 0; i < x; i++)
        printw("-");
    printw("+\n");
}
