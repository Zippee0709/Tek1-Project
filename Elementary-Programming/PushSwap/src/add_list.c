/*
** EPITECH PROJECT, 2018
** add_list.c
** File description:
** all usefull add list function
*/

#include "my.h"
#include "pushswap.h"

DlistNode *create_element(int const nb)
{
    DlistNode *element = malloc(sizeof(*element));

    if (element == NULL) {
        my_putstr_err("Error : Allocation failed for DlistNode\n");
        return (NULL);
    }
    element->value = nb;
    element->back = NULL;
    element->next = NULL;
    return (element);
}

Dlist *add_begin_list(Dlist *list, int const nb)
{
    DlistNode *element = create_element(nb);

    if (element == NULL)
        return (NULL);
    if (list->begin == NULL) {
        list->begin = element;
        list->end = element;
    }
    else {
        list->begin->back = element;
        element->next = list->begin;
        list->begin = element;
    }
    list->length = list->length + 1;
    return (list);
}

Dlist *add_end_list(Dlist *list, int const nb)
{
    DlistNode *element = create_element(nb);

    if (element == NULL)
        return (NULL);
    if (list->length == 0) {
        list->begin = element;
        list->end = element;
    }
    else {
        list->end->next = element;
        element->back = list->end;
        list->end = element;
    }
    list->length = list->length + 1;
    return (list);
}

Dlist *delete_end_list(Dlist *list)
{
    if (list->length == 0) {
        my_putstr_err("Error : the list is empty\n");
        return (new_list());
    }
    if (list->length == 1) {
        free(list);
        return (new_list());
    }

    DlistNode *temp = list->end;

    list->end = list->end->back;
    list->end->next = NULL;
    temp->next = NULL;
    temp->back = NULL;
    free(temp);
    list->length = list->length - 1;
    return (list);
}

Dlist *delete_begin_list(Dlist *list)
{
    if (list->length == 0) {
        my_putstr_err("Error : the list is empty\n");
        return (new_list());
    }
    else if (list->length == 1) {
        free(list->begin);
        free(list);
        return (new_list());
    }
    DlistNode *temp = list->begin;

    list->begin = list->begin->next;
    list->begin->back = NULL;
    temp->next = NULL;
    temp->back = NULL;
    free(temp);
    list->length = list->length - 1;
    return (list);
}
