/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** check.c
*/

#include "dante.h"

static void my_push_pos_in_list(Dante_t *dante)
{
    if (my_check_neighbour_avaible(dante) > 0)
        dante->list = add_end_list(dante->list, dante->pos);
}

int my_check_neighbour(Dante_t *dante, Cell_t *map, Cell_t *back)
{
    if (map->visited == FALSE) {
        my_set_road_in_map(map);
        my_set_road_in_map(back);
        my_push_pos_in_list(dante);
        return (1);
    }
    return (0);
}

int my_check_is_wall(Cell_t **map, int x, int y)
{
    if (map[y][x].c == 'X')
        return (1);
    return (0);
}

void my_check_in_list(Dlist_t *list, Dante_t *dante)
{
    DlistNode_t *tmp;
    int nb = 0;

    if (list == NULL)
        return;
    tmp = list->begin;
    while (tmp != NULL) {
        dante->pos = tmp->pos;
        nb = my_check_neighbour_avaible(dante);
        if (nb > 0)
            return;
        else {
            tmp = tmp->next;
            list = pop_begin_list(list);
        }
    }
}

void my_check_last_line(Cell_t **map, Pos_t *p)
{
    int road = 0;

    for (p->y = 0; p->y < p->max_y; p->y++) {
        road = my_get_success_road_hor(map, p->max_x, p->y);
        if (road >= 2)
            map[p->y][p->max_x - 1].c = '*';
    }
    for (p->x = 0; p->x < p->max_x; p->x++) {
        road = my_get_success_road_ver(map, p->max_y, p->x);
        if (road >= 2)
            map[p->max_y - 1][p->x].c = '*';
    }
    my_set_exit_cell(map, p);
}
