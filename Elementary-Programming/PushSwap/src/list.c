/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** all usefull function for list
*/

#include "my.h"
#include "pushswap.h"

Dlist *new_list(void)
{
    Dlist *list = malloc(sizeof(*list));

    if (list == NULL) {
        my_putstr_err("Error : Allocation memory failed for Dlist\n");
        return (NULL);
    }
    list->length = 0;
    list->begin = NULL;
    list->end = NULL;
    return (list);
}

void my_print_list(Dlist *list)
{
    DlistNode *temp;

    if (list->begin == NULL) {
        my_putstr_err("Error : the list is empty\n");
        return;
    }
    temp = list->begin;
    while (temp != NULL) {
        my_printf("[%d] ", temp->value);
        temp = temp->next;
    }
    my_putchar('\n');
}

Dlist *my_add_in_list(Dlist *list, int ac, char **av)
{
    int i = my_init_index(av[1]);

    while (i != ac) {
        add_end_list(list, my_getnbr(av[i]));
        i = i + 1;
    }
    return (list);
}

Dlist *my_free_list(Dlist *list)
{
    int i = list->length;

    while (i != 0) {
        delete_begin_list(list);
        i = i - 1;
    }
    return (list);
}
