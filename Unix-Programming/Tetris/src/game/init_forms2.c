/*
** EPITECH PROJECT, 2019
** init_forms
** File description:
** init_forms
*/

#include "tetris.h"
#include "my.h"

shape_t my_init_t(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("010");
    shape.shape[1] = my_strdup("111");
    shape.shape[2] = my_strdup("000");
    return (shape);
}

shape_t my_init_square(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("11");
    shape.shape[1] = my_strdup("11");
    return (shape);
}

shape_t my_init_bar(int size, int x, int y)
{
    shape_t shape;

    shape.x = x;
    shape.y = y;
    shape.size = size;
    shape.shape = malloc(sizeof(char *) * (size + 1));
    shape.shape[0] = my_strdup("0000");
    shape.shape[1] = my_strdup("1111");
    shape.shape[2] = my_strdup("0000");
    shape.shape[3] = my_strdup("0000");
    return (shape);
}
