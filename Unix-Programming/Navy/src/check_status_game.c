/*
** EPITECH PROJECT, 2019
** check_status_game.c
** File description:
** check_status_game.c
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void my_handler_catch_end(int signum, siginfo_t *info, void *ucontext)
{
    char status[1];

    (void)ucontext;
    if (signum == SIGUSR1)
        status[0] = '0';
    else
        status[0] = '1';
    ptr = &status;
    kill(info->si_pid, SIGUSR1);
}

int my_check_buffer_status(global_t *game)
{
    char *buffer = ptr;

    if (buffer[0] == '0') {
        game->value = 0;
        return (1);
    }
    return (0);
}

int my_catch_end_signal(int status, int pid, global_t *game)
{
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    signal.sa_sigaction = my_handler_catch_end;
    signal.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &signal, NULL) == -1 ||
        sigaction(SIGUSR2, &signal, NULL) == -1) {
        my_putstr_fd(2, "Error catch signal\n");
        return (-1);
    }
    pause();
    kill(pid, SIGUSR1);
    if (my_check_buffer_status(game) == 1)
        return (0);
    return (status);
}

int my_sent_game_status(int status, pid_t pid, global_t *game)
{
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    signal.sa_handler = my_handler_sent;
    usleep(100000);
    if (status == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    sigaction(SIGUSR1, &signal, NULL);
    pause();
    if (status == 0) {
        game->value = 1;
        return (0);
    }
    return (status);
}

int check_status_game(char m[MAP_MAX][MAP_MAX], char me[MAP_MAX][MAP_MAX],
                        global_t *game, int status)
{
    if (status == -1)
        return (status);
    status = get_status(m);
    if (game->pid_one == 0 ) {
        status = my_sent_game_status(status, game->pid_two, game);
        status = my_catch_end_signal(status, game->pid_two, game);
        print_map_status(status, game, m, me);
    }
    else {
        status = my_catch_end_signal(status, game->pid_one, game);
        status = my_sent_game_status(status, game->pid_one, game);
        print_map_status(status, game, m, me);
    }
    return (status);
}

