/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** display a content of an array of words
*/

#include "my.h"

int my_show_word_array(char * const * tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i = i + 1;
    }
    return (0);
}
