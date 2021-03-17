/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** all init function
*/

#include "dante.h"

static void my_init_visited_cell(Cell_t **map, int x, int y)
{
    Pos_t pos;

    my_init_pos(&pos, x, y);
    for (pos.y = 0; pos.y < y; pos.y += 2) {
        for (pos.x = 0; pos.x < x; pos.x += 2) {
            map[pos.y][pos.x].visited = FALSE;
        }
    }
}

static Cell_t **my_init_cell(Cell_t **map, int x, int y)
{
    Pos_t pos;

    my_init_pos(&pos, x, y);
    for (pos.y = 0; pos.y < y; pos.y++) {
        for (pos.x = 0; pos.x < x; pos.x++) {
            map[pos.y][pos.x].c = 'X';
            map[pos.y][pos.x].visited = TRUE;
        }
    }
    my_init_visited_cell(map, x , y);
    return (map);
}

static Cell_t **my_init_map(int x, int y)
{
    int i = 0;
    Cell_t **map = malloc(sizeof(Cell_t *) * (y));

    if (map == NULL)
        return (NULL);
    while (i < y) {
        map[i] = malloc(sizeof(Cell_t) * (x));
        if (map[i] == NULL)
            return (NULL);
        i++;
    }
    map = my_init_cell(map, x, y);
    return (map);
}

int my_init_dante(Dante_t *dante, int ac, char **av)
{
    dante->pos.max_x = atoi(av[1]);
    dante->pos.max_y = atoi(av[2]);
    dante->list = NULL;
    if (my_error_size(dante->pos.max_x, dante->pos.max_y) == 84)
        return (84);
    if (my_error_type(dante, ac, av) == 84)
        return (84);
    dante->map = my_init_map(dante->pos.max_x, dante->pos.max_y);
    if (dante->map == NULL)
        return (84);
    return (0);
}
