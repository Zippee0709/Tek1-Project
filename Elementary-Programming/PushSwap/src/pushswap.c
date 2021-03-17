/*
** EPITECH PROJECT, 2018
** pushswap.c
** File description:
** all usefull function for pushswap
*/

#include "my.h"
#include "pushswap.h"

void my_sort_list(Dlist *list_a, Dlist *list_b)
{
    int i = 0;
    int j = 1;
    int k = list_a->length;

    while (j != k) {
        while (i != k - j) {
            if (list_a->begin->value > list_a->begin->next->value)
                my_sa(list_a);
            my_pb(&list_a, &list_b);
            i = i + 1;
        }
        while (list_b->length != 0)
            my_pa(&list_a, &list_b, i);
        i = 0;
        j = j + 1;
    }
}

void my_check_list(Dlist *list_a, Dlist *list_b, int ac)
{
    DlistNode *temp = list_a->begin;
    int i = 1;

    if (list_a->length == 1)
        return;
    while (temp->next != NULL && temp->value < temp->next->value) {
        i = i + 1;
        temp = temp->next;
    }
    if (i != ac - 1)
        my_sort_list(list_a, list_b);
}

void my_pushswap(Dlist *list_a, Dlist *list_b, int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    else {
        my_add_in_list(list_a, ac, av);
        my_check_list(list_a, list_b, ac);
        my_printf("\n");
        my_free_list(list_a);
    }
}
