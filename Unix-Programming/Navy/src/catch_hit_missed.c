/*
** EPITECH PROJECT, 2019
** catch_hit_missed.c
** File description:
** catchèhit_missed.c
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void my_handler_catch_hit(int signum, siginfo_t *info, void *ucontext)
{
    char buffer[1];

    (void)ucontext;
    if (signum == SIGUSR1) {
        my_putstr(":  hit\n\n");
        buffer[0] = '1';
    }
    else if (signum == SIGUSR2) {
        my_putstr(":  missed\n\n");
        buffer[0] = '0';
    }
    ptr = &buffer;
    kill(info->si_pid, SIGUSR1);
}

void my_update_enemy(char *coord, char map[MAP_MAX][MAP_MAX])
{
    int letter = my_get_number(coord[0]);
    int number = my_get_number(coord[1]) - 1;
    char *status = ptr;

    if (status[0] == '1')
        map[number][letter] = 'x';
    else
        map[number][letter] = 'o';
}

int my_catch_missed_hit_signal(char *buffer, char map[MAP_MAX][MAP_MAX])
{
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    my_putstr(buffer);
    signal.sa_sigaction = my_handler_catch_hit;
    signal.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &signal, NULL) == -1 ||
        sigaction(SIGUSR2, &signal, NULL) == -1) {
        my_putstr_fd(2, "Error catch signal\n");
        return (-1);
    }
    pause();
    my_update_enemy(buffer, map);
    return (0);
}
