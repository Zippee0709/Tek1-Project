/*
** EPITECH PROJECT, 2018
** my_rev_list.c
** File description:
** revers the order of the list
*/

#include "include/my.h"
#include "include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *element = NULL;
    linked_list_t *temp = *begin;
    linked_list_t *next;

    while (temp != NULL) {
        next = temp->next;
        temp->next = element;
        element = temp;
        temp = next;
    }
    *begin = element;
}
