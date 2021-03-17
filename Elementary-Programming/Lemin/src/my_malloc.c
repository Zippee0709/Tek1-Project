/*
** EPITECH PROJECT, 2019
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "lemin.h"
#include "my.h"

char **my_malloc_dtab(int height, int length)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * (height + 1));

    if (tab == NULL)
        return (NULL);
    while (i < height) {
        tab[i] = malloc(sizeof(char) * (length + 1));
        if (tab[i] == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

int **my_malloc_int_dtab(int height, int length)
{
    int i = 0;
    int **tab = malloc(sizeof(int *) * (height + 1));

    if (tab == NULL)
        return (NULL);
    while (i < height) {
        tab[i] = malloc(sizeof(int) * (length + 1));
        if (tab[i] == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
