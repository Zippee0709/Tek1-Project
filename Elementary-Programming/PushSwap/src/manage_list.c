/*
** EPITECH PROJECT, 2018
** manage_list.c
** File description:
** all usefull function for manage list
*/

#include "my.h"
#include "pushswap.h"

Dlist *my_sa(Dlist *list)
{
    DlistNode *element = list->begin;

    if (list->begin->next != NULL) {
        list->begin = list->begin->next;
        list->begin->back = NULL;
        element->back = list->begin;
        element->next = list->begin->next;
        list->begin->next = element;
        my_printf("sa ");
    }
    return (list);
}

void my_pa(Dlist **list_a, Dlist **list_b, int i)
{
    int value = 0;

    if ((*list_b)->begin != NULL) {
        value = (*list_b)->begin->value;
        *list_b = delete_begin_list(*list_b);
        *list_a = add_begin_list(*list_a, value);
    }
    if (i == 1)
        my_printf("pa");
    else
        my_printf("pa ");
}

void my_pb(Dlist **list_a, Dlist **list_b)
{
    int value = 0;

    if ((*list_a)->begin != NULL) {
        value = (*list_a)->begin->value;
        *list_a = delete_begin_list(*list_a);
        *list_b = add_begin_list(*list_b, value);
        my_printf("pb ");
    }
}
