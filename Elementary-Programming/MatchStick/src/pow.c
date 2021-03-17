/*
** EPITECH PROJECT, 2019
** pow.c
** File description:
** all usefull function for calc pow
*/

#include "my.h"
#include "matchstick.h"

int pow_1(int *nb, s_ai *ai)
{
    if (*nb >= 1) {
        *nb = *nb - 1;
        ai->pow_1 = ai->pow_1 + 1;
        return (1);
    }
    return (0);
}

int pow_2(int *nb, s_ai *ai)
{
    if (*nb >= 2) {
        *nb = *nb - 2;
        ai->pow_2 = ai->pow_2 + 1;
        return (1);
    }
    return (0);
}

int pow_4(int *nb, s_ai *ai)
{
    if (*nb >= 4) {
        *nb = *nb - 4;
        ai->pow_4 = ai->pow_4 + 1;
        return (1);
    }
    return (0);
}

void winner(s_game *game)
{
    my_putstr("You lost, too bad...\n");
    my_free_dtab(game->map);
}

void looser(s_game *game)
{
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    my_free_dtab(game->map);
}
