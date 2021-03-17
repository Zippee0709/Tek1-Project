/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** all usefull function for free
*/

#include "my.h"
#include "matchstick.h"

void my_free_dtab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab[i]);
    free(tab);
}
