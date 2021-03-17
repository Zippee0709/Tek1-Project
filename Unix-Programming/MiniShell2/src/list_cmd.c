/*
** EPITECH PROJECT, 2019
** list_cmd.c
** File description:
** list_cmd.c
*/

#include "minishell.h"

static Dlist_cmd *my_fill_elem(Dlist_cmd *list, DlistElement *element)
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

static Dlist_cmd *push_back_cmd_dlist(Dlist_cmd *order, char *str)
{
    DlistElement *element = malloc(sizeof(*element));

    if (element == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        return (NULL);
    }
    element->cmd = my_str_to_word_tab(str, ' ');
    element->next = NULL;
    element->back = NULL;
    order = my_fill_elem(order, element);
    if (order == NULL)
        return (NULL);
    return (order);
}

static Dlist_cmd *free_last_element(Dlist_cmd *list)
{
    if (list->begin == list->end) {
        my_free_dtab(list->begin->cmd);
        free(list->begin);
        free(list);
        return (NULL);
    }
    return (list);
}

Dlist_cmd *pop_back_cmd_dlist(Dlist_cmd *list)
{
    DlistElement *tmp = NULL;

    if (list == NULL)
        return (NULL);
    if (free_last_element(list) == NULL)
        return (NULL);
    tmp = list->end;
    list->end = list->end->back;
    list->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    my_free_dtab(tmp->cmd);
    free(tmp);
    list->length--;
    return (list);
}

Dlist_cmd *split_cmd_in_dlist(Dlist_cmd *order, char *str)
{
    int i = 0;
    char **cmd = my_str_to_word_cmd(str);

    while (cmd[i] != NULL) {
        order = push_back_cmd_dlist(order, cmd[i]);
        i++;
    }
    my_free_dtab(cmd);
    return (order);
}
