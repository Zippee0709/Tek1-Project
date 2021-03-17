/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** all usefull function for check
*/

#include "runner.h"

void check_nb_monster(s_game *game)
{
    if (game->nb_zombie == 1)
        game->m1 = 1;
    else if (game->nb_zombie == 2) {
        game->m1 = 1;
        game->m2 = 1;
    }
    else if (game->nb_zombie == 3) {
        game->m1 = 1;
        game->m2 = 1;
        game->m3 = 1;
    }
}
