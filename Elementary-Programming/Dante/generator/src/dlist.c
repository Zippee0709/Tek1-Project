/*
** EPITECH PROJECT, 2019
** dlist.c
** File description:
** dlist.c
*/

#include "dante.h"

static Dlist_t *my_fill_dlist(Dlist_t *list, DlistNode_t *node)
{
    if (list == NULL) {
        list = malloc(sizeof(*list));
        if (list == NULL)
            return (NULL);
        list->begin = node;
        list->end = node;
        list->length = 0;
    }
    else {
        list->end->next = node;
        node->back = list->end;
        list->end = node;
    }
    list->length++;
    return (list);
}

Dlist_t *add_end_list(Dlist_t *list, Pos_t pos)
{
    DlistNode_t *node = malloc(sizeof(*node));

    if (node == NULL)
        return (NULL);
    node->pos = pos;
    node->back = NULL;
    node->next = NULL;
    list = my_fill_dlist(list, node);
    if (list == NULL)
        return (NULL);
    return (list);
}

Dlist_t *pop_end_list(Dlist_t *list)
{
    DlistNode_t *tmp;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free(list->begin);
        free(list);
        return (NULL);
    }
    tmp = list->end;
    list->end = list->end->back;
    list->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp);
    list->length--;
    return (list);
}

Dlist_t *pop_begin_list(Dlist_t *list)
{
    DlistNode_t *tmp;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free(list->begin);
        free(list);
        return (NULL);
    }
    tmp = list->begin;
    list->begin = list->begin->next;
    list->begin->back = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp);
    list->length--;
    return (list);
}
