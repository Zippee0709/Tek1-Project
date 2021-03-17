/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** all usefull print function
*/

#include "my.h"
#include "sokoban.h"

void my_show_word_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i = i + 1;
    }
}

void my_print_result(int status)
{
    if (status == 0)
        my_printf("You win !\n");
    else if (status == 1)
        my_printf("You lose !\n");
}

void my_printw_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        printw("%s\n", tab[i]);
        i = i + 1;
    }
}

void my_searching_p(sokoban_s *sokoban, char **tab)
{
    int i = 0;
    int j = 0;

    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            if (tab[i][j] == 'P') {
                sokoban->x = i;
                sokoban->y = j;
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
}

void my_free_word_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab[i]);
    free(tab);
}
