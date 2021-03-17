/*
** EPITECH PROJECT, 2019
** init_forms.c
** File description:
** init_forms.c
*/

#include "my.h"
#include "tetris.h"

static shape_t my_init_s(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("011");
    shape.shape[1] = my_strdup("110");
    shape.shape[2] = my_strdup("000");
    return (shape);
}

static shape_t my_init_z(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("110");
    shape.shape[1] = my_strdup("011");
    shape.shape[2] = my_strdup("000");
    return (shape);
}

static shape_t my_init_normall(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("001");
    shape.shape[1] = my_strdup("111");
    shape.shape[2] = my_strdup("000");
    return (shape);
}

static shape_t my_init_invertedl(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("100");
    shape.shape[1] = my_strdup("111");
    shape.shape[2] = my_strdup("000");
    return (shape);
}

int my_init_tab_shape(game_t *game)
{
    game->tab_shape = malloc(sizeof(shape_t) * (7));

    if (game->tab_shape == NULL)
        return (-1);
    game->tab_shape[0] = my_init_s(3, 5, 0);
    game->tab_shape[1] = my_init_z(3, 5, 0);
    game->tab_shape[2] = my_init_normall(3, 5, 0);
    game->tab_shape[3] = my_init_invertedl(3, 5, 0);
    game->tab_shape[4] = my_init_t(3, 5, 0);
    game->tab_shape[5] = my_init_square(2, 5, 0);
    game->tab_shape[6] = my_init_bar(4, 5, 0);
    return (0);
}
