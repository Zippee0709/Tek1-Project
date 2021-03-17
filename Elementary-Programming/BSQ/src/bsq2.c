/*
** EPITECH PROJECT, 2018
** bsq2.c
** File description:
** all usefull function for bsq algorithl 2
*/

#include "my.h"
#include "bsq.h"

void my_check_tmp(bsq_s *bsq, int tmp, int tmp_x, int tmp_y)
{
    if (tmp >= bsq->index) {
        bsq->index = tmp;
        bsq->x = tmp + tmp_x - 1;
        bsq->y = tmp + tmp_y - 1;
    }
}

void my_replace_tab(bsq_s *bsq)
{
    int i = 0;
    int j = 0;

    while (i < bsq->index - 1) {
        while (j < bsq->index - 1) {
            bsq->tab[bsq->x][bsq->y - j] = 'x';
            j = j + 1;
        }
        j = 0;
        i = i + 1;
        bsq->x = bsq->x - 1;
    }
}

void only_one_char(bsq_s *bsq)
{
    int i = 0;
    int j = 0;

    while (bsq->tab[i] != NULL) {
        while (bsq->tab[i][j] != '\0') {
            if (bsq->tab[i][j] == '.') {
                bsq->tab[i][j] = 'x';
                return;
            }
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
}

void my_print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i = i + 1;
    }
}

void my_free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab);
}
