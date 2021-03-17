/*
** EPITECH PROJECT, 2019
** shape.c
** File description:
** shape.c
*/

#include "my.h"
#include "tetris.h"

shape_t my_copy_shape(shape_t shape)
{
    int i = 0;
    int j = 0;
    shape_t new;
    new.shape = malloc(sizeof(char *) * shape.size);

    for (i = 0; i < shape.size; i++) {
        new.shape[i] = malloc(sizeof(char *) * shape.size);
        for (j = 0; j < shape.size; j++) {
            new.shape[i][j] = shape.shape[i][j];
        }
    }
    new.size = shape.size;
    new.x = shape.x;
    new.y = shape.y;
    return (new);
}

void my_free_shape(shape_t *shape)
{
    int i = 0;

    if (shape == NULL)
        return;
    for (i = 0; i < shape->size; i++)
        free(shape->shape[i]);
    free(shape->shape);
}

shape_t my_get_new_shape(game_t *game)
{
    shape_t new = my_copy_shape(game->tab_shape[rand() % 7]);

    new.x = game->x / 2 - 1;
    new.y = 0;
    return (new);
}
