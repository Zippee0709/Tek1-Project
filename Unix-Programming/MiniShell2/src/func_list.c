/*
** EPITECH PROJECT, 2019
** func_list.c
** File description:
** function_list.c
*/

#include "minishell.h"

void print_list(Dlist_t *list)
{
    DlistNode *tmp = NULL;

    if (list == NULL) {
        my_putstr_err("Error : List are empty\n");
        return;
    }
    tmp = list->begin;
    while (tmp != NULL) {
        my_putstr(tmp->str);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

void print_list_cmd(Dlist_cmd *list)
{
    DlistElement *tmp = NULL;
    int i = 0;

    if (list == NULL) {
        my_putstr_err("Error : List are empty\n");
        return;
    }
    tmp = list->begin;
    while (tmp != NULL) {
        while (tmp->cmd[i] != NULL) {
            my_putstr(tmp->cmd[i]);
            my_putchar(' ');
            i++;
        }
        i = 0;
        my_putchar('$');
        my_putchar('\n');
        tmp = tmp->next;
    }
}

void free_list_cmd(Dlist_cmd *list)
{
    while (list != NULL)
        list = pop_back_cmd_dlist(list);
    list = NULL;
}

void free_list(Dlist_t *list)
{
    while (list != NULL)
        list = pop_back_dlist(list);
    list = NULL;
}
