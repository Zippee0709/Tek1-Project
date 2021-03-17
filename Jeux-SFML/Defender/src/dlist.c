/*
** EPITECH PROJECT, 2019
** dlist.c
** File description:
** dlis.c
*/

#include "my_defender.h"

int dlist_lenght(Dlist *list)
{
    if (list == NULL)
        return (0);
    return (list->lenght);
}

Dlist *my_fill_dlist(Dlist *list, Dlist_node *element)
{
    if (list == NULL) {
        list = malloc(sizeof(*list));
        if (list == NULL) {
            my_putstr_err("Error : Allocation memery failed\n");
            return (NULL);
        }
        list->lenght = 0;
        list->begin = element;
        list->end = element;
    }
    else {
        list->end->next = element;
        element->back = list->end;
        list->end = element;
    }
    list->lenght++;
    return (list);
}

Dlist *push_back_dlist(Dlist *list, s_obj obj, sfVector2f pos)
{
    Dlist_node *element = malloc(sizeof(*element));

    if (element == NULL) {
        my_putstr_err("Error : Allocation memery failed\n");
        return (NULL);
    }
    element->obj.sprite = obj.sprite;
    element->obj.texture = obj.texture;
    element->obj.pos = pos;
    element->obj.rect = obj.rect;
    element->obj.clock = sfClock_create();
    element->obj.type = 0;
    element->obj.stat = init_stat_tower(3);
    element->next = NULL;
    element->back = NULL;
    list = my_fill_dlist(list, element);
    return (list);
}

Dlist *pop_back_dlist(Dlist *list)
{
    Dlist_node *tmp;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free(list);
        return (NULL);
    }
    tmp = list->end;
    list->end = list->end->back;
    list->end->next = NULL;
    tmp->back = NULL;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    list->lenght--;
    return (list);
}

Dlist *pop_begin_dlist(Dlist *list)
{
    Dlist_node *tmp;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free(list);
        return (NULL);
    }
    tmp = list->begin;
    list->begin = list->begin->next;
    list->begin->back = NULL;
    tmp->back = NULL;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    list->lenght--;
    return (list);
}
