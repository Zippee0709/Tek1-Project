/*
** EPITECH PROJECT, 2019
** ants_travel.c
** File description:
** ants_travels.c
*/

#include "lemin.h"
#include "my.h"

int my_get_next_rooms(Graph *close, DlistAnts *ants)
{
    int i = 0;
    int j = 0;
    DlistNode *tmp;

    if (close == NULL)
        return (-1);
    tmp = close->tab[ants->ants_pos].begin;
    while (tmp->value != ants->ants_rooms)
        tmp = tmp->next;
    tmp->status = 0;
    tmp = tmp->next;
    if (tmp != NULL) {
        tmp->status = 1;
        return (tmp->value);
    }
    return (ants->ants_rooms);
}

int my_free_end_rooms(Graph *close, DlistAnts *ants, int end)
{
    int i = 0;
    int j = 0;
    DlistNode *tmp;

    if (close == NULL)
        return (-1);
    tmp = close->tab[ants->ants_pos].begin;
    while (tmp != NULL && tmp->value != end)
        tmp = tmp->next;
    tmp->status = 0;
}

int my_get_free_rooms(Graph *close, int *pos)
{
    int i = 0;
    int rooms = 0;
    DlistNode *tmp;

    if (close == NULL)
        return (-1);
    while (i < close->nb_vertices) {
        tmp = close->tab[i].begin;
        if (tmp->status == 0) {
            *pos = i;
            tmp->status = 1;
            return (tmp->value);
        }
        i++;
    }
    return (0);
}

void check_tmp_ants(Global_t *global, Graph *close, DlistAnts *tmp, int *i)
{
    if (tmp->ants_rooms == global->start)
        tmp->ants_rooms = my_get_free_rooms(close, &tmp->ants_pos);
    else if (tmp->ants_rooms == global->end) {
        my_free_end_rooms(close, tmp, global->end);
        *i = *i + 1;
    }
    else if (tmp->ants_rooms > 0)
        tmp->ants_rooms = my_get_next_rooms(close, tmp);
}

void my_ants_travel(Global_t *global, Graph *close)
{
    int i = 0;
    DlistAnts *tmp = global->ants;

    while (i < global->nb_ants) {
        tmp = global->ants;
        while (tmp != NULL) {
            check_tmp_ants(global, close, tmp, &i);
            tmp = tmp->next;
        }
        print_list_ants_status(global->ants, global->start, global->end);
        if (i != global->nb_ants - 1)
            my_putchar('\n');
    }
}
