/*
** EPITECH PROJECT, 2019
** dlist.c
** File description:
** dlist.c
*/

#include "../include/minishell.h"

List_t *push_back_list(List_t *list, char *str)
{
    List_t *element = malloc(sizeof(*element));
    List_t *tmp = NULL;
    
    if (element == NULL)
        return (NULL);
    element->str = strdup(str);
    element->next = NULL;
    if (list == NULL)
        return (element);
    tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = element;
    return (list);
}

List_t *pop_front_list(List_t *list)
{
    List_t *element = malloc(sizeof(*element));

    if (element == NULL)
        return (NULL);
    element = list->next;
    free(list);
    list = NULL;
    return (element);
}

void print_list(List_t *list)
{
    if (list == NULL)
        return;
    while (list != NULL) {
        write(0, list->str, strlen(list->str));
        list = list->next;
    }
}

void free_list(List_t *list)
{
    if (list == NULL)
        return;
    while (list != NULL)
        list = pop_front_list(list);
    free(list);
}
