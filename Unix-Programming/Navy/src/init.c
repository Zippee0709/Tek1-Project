/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** all usefull init function
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void init_pid(pid_t pid_one, pid_t pid_two, int player, global_t *game)
{
    game->pid_one = pid_one;
    game->pid_two = pid_two;
    game->player = player;
}

void init_all(char **pos, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX])
{
    fill_map_null(map_enemy);
    start_fill_map(pos, map);
}
