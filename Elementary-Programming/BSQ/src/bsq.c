/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** all usefull funtion for bsq algorithm
*/

#include "my.h"
#include "bsq.h"

int my_check_next(bsq_s *bsq, int tmp, int x, int y)
{
    int i = 0;

    if (bsq->tab[x][y] != '.')
        return (0);
    while (i < tmp) {
        if (bsq->tab[x][y + i] != '.' || bsq->tab[x + i][y] != '.')
            return (0);
        i = i + 1;
    }
    return (1);
}

void my_search_next_case(bsq_s *bsq, int *x, int *y)
{
    int tmp = 1;
    int tmp_x = *x;
    int tmp_y = *y;

    while (tmp_x >= 0 && tmp_y >= 0 &&
           my_check_next(bsq, tmp, tmp_x, tmp_y) == 1) {
        tmp_x = tmp_x - 1;
        tmp_y = tmp_y - 1;
        tmp = tmp + 1;
    }
    my_check_tmp(bsq, tmp, tmp_x, tmp_y);
}

void my_search_bsq(bsq_s *bsq, int *x, int *y)
{
    if (bsq->tab[*x][*y] == 'o' && *y != 0) {
        *y = *y - 1;
    }
    else if (*y == 0) {
        *x = *x - 1;
        *y = bsq->lenght - 1;
    }
    else if (bsq->tab[*x][*y] == '.') {
        my_search_next_case(bsq, x, y);
        *y = *y - 1;
    }
}

void my_bsq_algorithm(bsq_s *bsq)
{
    int i = 0;
    int x = bsq->width - 1;
    int y = bsq->lenght - 1;

    while (i < (bsq->lenght * bsq->width)) {
        my_search_bsq(bsq, &x, &y);
        i = i + 1;
    }
    if (bsq->index <= 2)
        only_one_char(bsq);
    else
        my_replace_tab(bsq);
}
