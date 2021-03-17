/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game.c
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void check_pid_send_signal(char *buffer, pid_t pid_one, pid_t pid_two)
{
    if (pid_one == 0)
        sent_signal(buffer, pid_two);
    else
        sent_signal(buffer, pid_one);
}

int game_pending(global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX])
{
    int status = 1;
    int i = 0;

    while (status == 1) {
        if (i >= 2) {
            print_all_map(game, map, map_enemy);
            i = 0;
        }
        if (game->player == 1)
            status = on_turn(map_enemy, game->pid_one, game->pid_two);
        else
            wait_turn(map, game->pid_one, game->pid_two);
        status = check_status_game(map, map_enemy, game, status);
        game->player *= -1;
        i++;
    }
    return (status);
}

