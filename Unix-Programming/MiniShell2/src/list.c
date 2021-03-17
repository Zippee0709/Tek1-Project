/*
** EPITECH PROJECT, 2019
** env_list.c
** File description:
** env_list.c
*/

#include "minishell.h"

static Dlist_t *my_fill_dlist(Dlist_t *list, DlistNode * element)
{
    if (list == NULL) {
        list = malloc(sizeof(*list));
        if (list == NULL) {
            my_putstr_err("Error : Allocation memory failed\n");
            return (NULL);
        }
        list->length = 0;
        list->begin = element;
        list->end = element;
    }
    else {
        list->end->next = element;
        element->back = list->end;
        list->end = element;
    }
    list->length++;
    return (list);
}

Dlist_t *push_back_dlist(Dlist_t *list, char *str)
{
    DlistNode *element = malloc(sizeof(*element));

    if (element == NULL)
        return (NULL);
    element->str = my_strdup(str);
    element->back = NULL;
    element->next = NULL;
    list = my_fill_dlist(list, element);
    if (list == NULL)
        return (NULL);
    return (list);
}

static void free_list_element(Dlist_t *list)
{
    free(list->begin->str);
    free(list->begin);
    free(list);
}

Dlist_t *pop_back_dlist(Dlist_t *list)
{
    DlistNode *tmp = NULL;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free_list_element(list);
        return (NULL);
    }
    tmp = list->end;
    list->end = list->end->back;
    list->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp->str);
    free(tmp);
    list->length--;
    return (list);
}

Dlist_t *pop_begin_dlist(Dlist_t *list)
{
    DlistNode *tmp = NULL;

    if (list == NULL)
        return (NULL);
    else if (list->begin == list->end) {
        free_list_element(list);
        return (NULL);
    }
    tmp = list->end;
    list->end = list->end->back;
    list->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp->str);
    free(tmp);
    list->length--;
    return (list);
}
