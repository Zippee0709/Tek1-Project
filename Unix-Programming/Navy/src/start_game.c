/*
** EPITECH PROJECT, 2019
** start_game.c
** File description:
** start the game of navy
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

static int check_buffer(char *buffer, int rd_return)
{
    if (my_strlen(buffer) != 3 || buffer == NULL || buffer[0] == '\0') {
        my_putstr("wrong position\n");
        return (-1);
    }
    if (buffer[1] < '1' || buffer[1] > '8' ||
        buffer[0] < 'A' || buffer[0] > 'H' || rd_return != 3) {
        my_putstr("wrong position\n");
        return (-1);
    }
    buffer[2] = '\0';
    return (0);
}

int on_turn(char map_enemy[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two)
{
    char buffer[2];
    int rd_return = 0;

    do {
        buffer[0] = 0;
        buffer[1] = 0;
        buffer[2] = 0;
        my_putstr("attack:  ");
        rd_return = read(0, buffer, 5);
    } while (check_buffer(buffer, rd_return) != 0 && my_strlen(buffer));
    if (my_strlen(buffer) == 0) {
        return (-1);
    }
    check_pid_send_signal(buffer, pid_one, pid_two);
    my_catch_missed_hit_signal(buffer, map_enemy);
    return (0);
}

void wait_turn(char map[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two)
{
    my_putstr("waiting for enemy's attack...\n");
    catch_signal();
    my_update(map, pid_one, pid_two);
}

int start_game(char **pos, char map[MAP_MAX][MAP_MAX], int player, int pid_one)
{
    char map_enemy[MAP_MAX][MAP_MAX];
    pid_t pid_two = 0;
    global_t game;

    if (ptr != NULL) {
        pid_two = my_getnbr((char *)ptr);
        free(ptr);
    }
    init_all(pos, map, map_enemy);
    init_pid(pid_one, pid_two, player, &game);
    print_all_map(&game, map, map_enemy);
    if (game_pending(&game, map, map_enemy) == -1)
        return (0);
    return (game.value);
}
