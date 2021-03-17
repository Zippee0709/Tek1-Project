/*
** EPITECH PROJECT, 2019
** create_node.c
** File description:
** create_node.c
*/

#include "lemin.h"
#include "my.h"

DlistAnts *add_ants(DlistAnts *list, int ants_nb, int ants_rooms)
{
    DlistAnts *ants = malloc(sizeof(DlistAnts));
    DlistAnts *tmp;

    if (ants == NULL) {
        my_put_error("Error : Allocation memory failed\n");
        return (NULL);
    }
    ants->ants_nb = ants_nb;
    ants->ants_rooms = ants_rooms;
    ants->ants_pos = 0;
    ants->status = 0;
    ants->next = NULL;
    if (list == NULL)
        return (ants);
    tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = ants;
    return (list);
}

DlistNode *add_node(int value)
{
    DlistNode *node = malloc(sizeof(DlistNode));

    if (node == NULL) {
        my_put_error("Error : Allocation memory failed\n");
        return (NULL);
    }
    node->value = value;
    node->status = 0;
    node->next = NULL;
    return (node);
}

void add_edge(Graph *graph, int src, int dest)
{
    DlistNode *node = add_node(dest);
    node->next = graph->tab[src].begin;
    graph->tab[src].begin = node;
    graph->tab[src].length++;

    if (graph->status == 1) {
        node = add_node(src);
        node->next = graph->tab[dest].begin;
        graph->tab[dest].begin = node;
        graph->tab[dest].length++;
    }
}

void add_value(Graph *graph, int src, int dest)
{
    DlistNode *node = add_node(dest);
    DlistNode *tmp = graph->tab[src].begin;

    if (tmp == NULL) {
        graph->tab[src].begin = node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    graph->tab[src].length++;
}
