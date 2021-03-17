/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for pushswap project
*/

#include "my.h"
#include "pushswap.h"

int main(int ac, char **av)
{
    Dlist *list_a = new_list();
    Dlist *list_b = new_list();

    if (list_a == NULL || list_b == NULL) {
        my_putstr_err("Error : no enought argument\n");
        return (84);
    }
    else if (ac < 2) {
        my_putstr_err("Error : no enought argument\n");
        return (84);
    }
    else
        my_pushswap(list_a, list_b, ac, av);
}
