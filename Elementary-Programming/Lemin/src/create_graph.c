/*
** EPITECH PROJECT, 2019
** create_graph.c
** File description:
** create_graph.c
*/

#include "lemin.h"
#include "my.h"

static AdjencyList *fill_null_to_begin(AdjencyList *tab, int vertices)
{
    for (int i = 0; i < vertices; i++) {
        tab[i].begin = NULL;
        tab[i].length = 0;
    }
    return (tab);
}

Graph *new_graph(int vertices, int status)
{
    Graph *graph = malloc(sizeof(*graph));

    if (graph == NULL) {
        my_put_error("Error : Allocation memory failed\n");
        return (NULL);
    }
    graph->status = status;
    graph->nb_vertices = vertices;
    graph->tab = malloc(sizeof(AdjencyList) * vertices);
    if (graph->tab == NULL) {
        my_put_error("Error : Allocation memory failed\n");
        return (NULL);
    }
    graph->tab = fill_null_to_begin(graph->tab, vertices);
    return (graph);
}

void free_graph(Graph *graph)
{
    DlistNode *node = NULL;
    DlistNode *tmp = NULL;

    if (graph == NULL || graph->tab == NULL)
        return;
    if (graph->tab != NULL) {
        for (int i = 0; i < graph->nb_vertices; i++) {
            node = graph->tab[i].begin;
            while (node != NULL) {
                tmp = node;
                node = node->next;
                free(tmp);
            }
        }
        free(graph->tab);
    }
    free(graph);
}

void print_graph(Graph *graph)
{
    DlistNode *node = NULL;

    if (graph == NULL)
        return;
    for (int i = 0; i < graph->nb_vertices; i++) {
        node = graph->tab[i].begin;
        my_put_nbr(i);
        my_putstr(" : ");
        while (node != NULL) {
            my_putstr(" ");
            my_put_nbr(node->value);
            my_putstr(" ");
            node = node->next;
        }
        my_putchar('\n');
    }
}
