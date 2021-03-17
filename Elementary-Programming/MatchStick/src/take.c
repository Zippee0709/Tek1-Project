/*
** EPITECH PROJECT, 2019
** take.c
** File description:
** take.c
*/

#include "my.h"
#include "matchstick.h"

void take_1(s_game *game)
{
    game->ai_stick = 1;
    game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
}

void take_2(s_game *game)
{
    game->ai_stick = 2;
    game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
}

void take_4(s_game *game)
{
    game->ai_stick = 4;
    game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
}

