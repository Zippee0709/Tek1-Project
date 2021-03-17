/*
** EPITECH PROJECT, 2019
** player_two.c
** File description:
** player two file
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

int player_two(int pid_one, char *posfile)
{
    pid_t pid = getpid();
    char **pos;
    char map[MAP_MAX][MAP_MAX];
    int status = 0;

    my_putstr("my_pid:\t");
    my_put_nbr(pid);
    my_putstr("\n");
    if ((pos = read_pos(posfile)) == NULL)
        return (-1);
    if (kill(pid_one, SIGUSR2) == -1) {
        my_putstr_fd(1, "Connection failed.\n");
        return (-1);
    }
    my_putstr("successfully connected\n");
    status = start_game(pos, map, -1, pid_one);
    return (status);
}
