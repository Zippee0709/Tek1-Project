/*
** EPITECH PROJECT, 2019
** print2.c
** File description:
** print2.c
*/

#include "my.h"
#include "matchstick.h"

void my_print_game_info(s_game *game)
{
    if (game->evt == PLAYER) {
        my_printf("Player removed %d", game->user_stick);
        my_printf(" match(es) from line %d\n", game->user_line);
    }
    else if (game->evt == AI) {
        my_printf("AI removed %d", game->ai_stick);
        my_printf(" match(es) from line %d\n", game->ai_line);
    }
}

int my_find_nb_stick(s_game *game, s_ai *ai)
{
    if (ai->pow_4 == 1 && ai->pow_1 == 2) {
        game->ai_stick = 5;
        game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
        return (1);
    }
    else if (ai->pow_2 == 1 && ai->pow_1 == 2) {
        game->ai_stick = 3;
        game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
        return (1);
    }
    return (0);
}

void my_get_final_stick(s_game *game, s_ai *ai)
{
    if (ai->pow_4 == 1)
        game->ai_stick = 4;
    else if (ai->pow_2 == 2)
        game->ai_stick = 2;
    else
        game->ai_stick = 1;
    game->ai_line = my_search_nb_stick_on_map(game->map, game->ai_stick);
}
