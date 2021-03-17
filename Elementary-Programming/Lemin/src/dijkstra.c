/*
** EPITECH PROJECT, 2019
** dijkstra.c
** File description:
** dijkstra.c
*/

#include "lemin.h"
#include "my.h"

int my_check_node_status(int nb, Global_t *global)
{
    int i = 0;
    int **tab = global->status;

    while (tab[i] != NULL) {
        if (tab[i][0] == nb && tab[i][2] == 0) {
            global->status[i][2] = 1;
            return (0);
        }
        i++;
    }
    return (1);
}

void reset_value(int nb, Global_t *global)
{
    int i = 0;
    int **tab = global->status;

    while (tab[i] != NULL) {
        if (tab[i][0] == nb && tab[i][2] == 1)
            global->status[i][2] = 0;
        i++;
    }
}

int find_basic_possibility(Graph *graph, int src, int end)
{
    int nb_start = graph->tab[src].length;

    if (nb_start == 0) {
        my_putstr("Error : no possiblity !\n");
        return (-1);
    }
    return (nb_start);
}

void *my_search_in_node(Global_t *global, int *start, int end, int j)
{
    DlistNode *node = global->graph->tab[*start].begin;

    while (node != NULL) {
        if (my_check_node_status(node->value, global) == 0) {
            add_value(global->close, j, node->value);
            *start = node->value;
            node = NULL;
        } else
            node = node->next;
    }
}

Graph *my_dijkstra_pathfinder(Graph *graph, Graph *close, Global_t *global)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int start = global->start;

    while (k < global->nb_road) {
        while (start != global->end)
            my_search_in_node(global, &start, global->end, j);
        reset_value(global->end, global);
        start = global->start;
        k++;
        j++;
    }
    return (close);
}
