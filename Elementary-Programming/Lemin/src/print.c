/*
** EPITECH PROJECT, 2019
** print.c
** File description:
** print.c
*/

#include "lemin.h"
#include "my.h"

void print_list_ants_status(DlistAnts *ants, int start, int end)
{
    if (ants == NULL)
        return;
    while (ants != NULL) {
        if (ants->ants_rooms != start && ants->status == 0) {
            if (ants->ants_rooms == end)
                ants->status = 1;
            my_putchar('P');
            my_put_nbr(ants->ants_nb);
            my_putchar('-');
            my_put_nbr(ants->ants_rooms);
            my_putchar(' ');
        }
        ants = ants->next;
    }
}
