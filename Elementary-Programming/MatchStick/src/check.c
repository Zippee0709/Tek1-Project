/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** all usefull check function
*/

#include "my.h"
#include "matchstick.h"

int my_check_stick_on_map(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == '|')
                return (1);
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    return (0);
}

void change_turn(s_game *game)
{
    if (game->evt == PLAYER)
        game->evt = AI;
    else
        game->evt = PLAYER;
}

void my_check_winner(s_game *game)
{
    int status = my_check_stick_on_map(game->map);

    if (status == 0 && game->evt == PLAYER)
        game->result = 1;
    else if (status == 0 && game->evt == AI)
        game->result = 2;
    else
        change_turn(game);
}

int my_check_result(s_game *game)
{
    int status = my_check_stick_on_map(game->map);

    if (status == 0 && game->result == 1) {
        winner(game);
        return (1);
    }
    else if (status == 0 && game->result == 2) {
        looser(game);
        return (2);
    }
    return (0);
}
