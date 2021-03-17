/*
** EPITECH PROJECT, 2018
** my_sort_word_array.c
** File description:
** sort the words inside tab
*/

#include "include/my.h"

int my_check_word_to_sort(char **tab, int n)
{
    int i = 0;

    if (tab[n][i] < tab[n - 1][i] && n > 0)
        return (1);
    while (tab[n][i] == tab[n - 1][i] && n > 0)
        i = i + 1;
    if (tab[n][i] < tab[n - 1][i])
        return (1);
    return (0);
}

int my_sort_word_array(char **tab)
{    
    int i = 1;
    char *copy = NULL;

    while (tab[i] != NULL) {
        if (my_check_word_to_sort(tab, i) == 1) {
            copy = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = copy;
            i = i - 2;
        }
        i = i + 1;
    }
    return (0);
}
