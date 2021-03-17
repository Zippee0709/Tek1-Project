/*
** EPITECH PROJECT, 2018
** my_list_size.c
** File description:
** get size of list
*/

#include "include/my.h"
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        i = i + 1;
        begin = begin->next;
    }
    return (i);
}
