/*
** EPITECH PROJECT, 2019
** player_one.c
** File description:
** player one file
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "navy.h"

void *ptr = NULL;

void my_handler(int signum, siginfo_t *info, void *ucontext)
{
    (void)info;
    (void)ucontext;
    if (signum != SIGUSR2) {
        my_putstr_fd(2, "Error signal\n");
    } else {
        my_putstr("enemy connected\n");
        ptr = my_itoa(info->si_pid);
    }
}

void print_text(void)
{
    int pid = getpid();

    my_putstr("my_pid:\t");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
}

int player_one(char *posfile, int status)
{
    char **pos;
    char map[MAP_MAX][MAP_MAX];
    struct sigaction siga;

    sigemptyset(&siga.sa_mask);
    siga.sa_sigaction = my_handler;
    siga.sa_flags = SA_SIGINFO;
    print_text();
    if ((pos = read_pos(posfile)) == NULL)
        return (-1);
    if (sigaction(SIGUSR2, &siga, NULL) == -1) {
        return (-1);
    }
    pause();
    status = start_game(pos, map, 1, 0);
    return (status);
}
