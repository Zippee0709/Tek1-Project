/*
** EPITECH PROJECT, 2019
** matchstick.c
** File description:
** all usefull function for matchstick
*/

#include "my.h"
#include "matchstick.h"

void update_game(s_game *game)
{
    int i = 0;
    int pos = my_get_last_stick_pos(game->map, game->user_line);

    while (i < game->user_stick) {
        game->map[game->user_line][pos] = ' ';
        pos = pos - 1;
        i = i + 1;
    }
}

int game_func(s_game *game)
{
    if (game->evt == PLAYER) {
        my_print_map(game->map);
        my_print_turn(game->evt);
        if (my_print_all(game) == -1)
            return (-1);
        update_game(game);
        my_check_winner(game);
    }
    else if (game->evt == AI) {
        my_print_map(game->map);
        my_print_turn(game->evt);
        my_ai_marienbad(game);
        my_check_winner(game);
    }
    return (0);
}

int matchstick(s_game *game, char **av)
{
    if (init_game(game, av) == 84)
        return (84);
    game->status = my_check_result(game);
    while (game->status == 0) {
        if (game_func(game) == -1)
            return (0);
        game->status = my_check_result(game);
        if (game->status == 1)
            return (1);
        else if (game->status == 2)
            return (2);
    }
    return (0);
}
