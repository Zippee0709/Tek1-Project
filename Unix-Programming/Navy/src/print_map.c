/*
** EPITECH PROJECT, 2019
** print_map.c
** File description:
** print map & enemy map for navy
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void print_map(char map[MAP_MAX][MAP_MAX])
{
    my_putstr(" | A B C D E F G H\n");
    my_putstr("-+----------------\n");
    for (int i = 0; i < MAP_MAX; i++) {
        my_put_nbr(i + 1);
        my_putstr("| ");
        for (int j = 0; j < MAP_MAX; j++) {
            my_putchar(map[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void print_map_for_second_player(int pid_one, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX])
{
    if (pid_one != 0) {
        my_putstr("my positions:\n");
        print_map(map);
        my_putstr("\nenemy's positions:\n");
        print_map(map_enemy);
    }
}

void print_all_map(global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX])
{
    print_map_for_second_player(game->pid_one, map, map_enemy);
    print_map_for_second_player(game->pid_two, map, map_enemy);
}

void print_map_status(int status, global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX])
{
    if (status == 0 && game->value == 0) {
        print_all_map(game, map, map_enemy);
        my_putstr("\nI won\n");
    }
    else if (status == 0  && game->value == 1) {
        print_all_map(game, map, map_enemy);
        my_putstr("\nEnemy won\n");
    }
}

int get_status(char map[MAP_MAX][MAP_MAX])
{
    int i = 0;
    int j = 0;

    while (i < MAP_MAX) {
        while (j < MAP_MAX) {
            if (map[i][j] >= '0' && map[i][j] <= '9') {
                return (1);
            }
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (0);
}
