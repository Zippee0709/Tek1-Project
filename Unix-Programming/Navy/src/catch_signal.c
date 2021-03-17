/*
** EPITECH PROJECT, 2019
** my_signal.c
** File description:
** all functions related to signal things
*/

#include <signal.h>
#include "my.h"
#include "navy.h"

static const int BITS = 8;

void check_if_its_new(int *i, int *nbr, char coord[2])
{
    if (*i > 7) {
        *i = 0;
        if (*nbr == 0)
            *nbr = 1;
        else {
            coord[0] = '\0';
            coord[1] = '\0';
            *nbr = 0;
        }
    }
}

void my_handler_coord(int signum, siginfo_t *info, void *ucontext)
{
    static int i = 0;
    static int nbr = 0;
    static char coord[2];

    (void)ucontext;
    check_if_its_new(&i, &nbr, coord);
    if (signum == SIGUSR1)
        coord[nbr] |= 0 << i;
    else if (signum == SIGUSR2)
        coord[nbr] |= 1 << i;
    usleep(1000);
    i++;
    kill(info->si_pid, SIGUSR1);
    if (i == 7 && nbr == 1) {
        coord[2] = '\0';
        ptr = &coord;
    }
}

int catch_signal(void)
{
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    signal.sa_sigaction = my_handler_coord;
    signal.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &signal, NULL) == -1 ||
        sigaction(SIGUSR2, &signal, NULL) == -1) {
        my_putstr_fd(2, "Error catch signal\n");
        return (-1);
    }
    for (int i = 0; i < (BITS * 2); i++) {
        pause();
    }
    return (0);
}
