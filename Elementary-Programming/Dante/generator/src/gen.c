/*
** EPITECH PROJECT, 2019
** gen.c
** File description:
** gen.c
*/

#include "dante.h"

int my_full_road(Cell_t **map, Pos_t *p, int nb_wall)
{
    if (p->max_x * p->max_y == 4 && nb_wall == 1) {
        map[p->max_y - 2][p->max_x - 1].c = '*';
        map[p->max_y - 1][p->max_x - 2].c = '*';
        return (0);
    }
    return (1);
}

void my_gen_imperfect_map(Cell_t **map, Pos_t *p, int nb_wall)
{
    int count = 0;
    int wall = my_get_wall_in_map(map, *p);

    if (my_full_road(map, p, nb_wall) == 0)
        return;
    while (count != nb_wall && wall > 0) {
        p->x = rand() % (p->max_x);
        p->y = rand() % (p->max_y);
        if (map[p->y][p->x].c == 'X') {
            map[p->y][p->x].c = '*';
            count++;
            wall = my_get_wall_in_map(map, *p);
        }
    }
}

void my_gen_small_maze(Cell_t **map, Pos_t *pos)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < pos->max_x; i++) {
        map[j][i].c = '*';
        map[j][i].visited = TRUE;
    }
    i = i - 1;
    for (j = 0; j < pos->max_y; j++) {
        map[j][i].c = '*';
        map[j][i].visited = TRUE;
    }
}

void my_gen_basic_maze(Dante_t *dante, Cell_t **map, Pos_t *p)
{
    int unvisited = my_get_nb_unvisited_cell(dante->map, dante->pos);

    while (unvisited > 0) {
        if (my_check_neighbour_avaible(dante) > 0)
            my_random_neighbour(dante, map, p);
        else
            my_check_in_list(dante->list, dante);
        unvisited = my_get_nb_unvisited_cell(dante->map, dante->pos);
    }
}

void my_gen_perfect_map(Dante_t *dante)
{
    srand(time(NULL));
    dante->pos.x = 0;
    dante->pos.y = 0;
    my_set_road_in_map(&dante->map[dante->pos.y][dante->pos.x]);
    if (dante->pos.max_x <= 2 || dante->pos.max_y <= 2)
        my_gen_small_maze(dante->map, &dante->pos);
    else
        my_gen_basic_maze(dante, dante->map, &dante->pos);
    my_check_last_line(dante->map, &dante->pos);
}
