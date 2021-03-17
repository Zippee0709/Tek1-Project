/*
** EPITECH PROJECT, 2019
** copy_env.c
** File description:
** copy_env.c
*/

#include "minishell.h"

Dlist_t *copy_double_tab_in_list(Dlist_t *list, char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (NULL);
    while (tab[i] != NULL) {
        list = push_back_dlist(list, tab[i]);
        i++;
    }
    return (list);
}

char **copy_list_in_double_tab(Dlist_t *list)
{
    int i = 0;
    DlistNode *tmp = NULL;
    char **tab = malloc(sizeof(char *) * (list->length + 1));

    if (tab == NULL)
        return (NULL);
    tmp = list->begin;
    while (tmp != NULL) {
        tab[i] = my_strdup(tmp->str);
        tmp = tmp->next;
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
