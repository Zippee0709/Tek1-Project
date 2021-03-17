/*
** EPITECH PROJECT, 2019
** sent_signal.c
** File description:
** sent signal for coordinate
*/

#include <signal.h>
#include "my.h"
#include "navy.h"

static const int BITS = 8;

void my_handler_sent(int signum)
{
    if (signum != SIGUSR1) {
        my_putstr_fd(2, "Error recup\n");
    } else {
        usleep(1000);
    }
}

void sent_signal_caractere(char carac, pid_t pid, struct sigaction signal)
{
    for (int i = 0; i < BITS; i++) {
        if (((carac >> i) & 1) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        sigaction(SIGUSR1, &signal, NULL);
        pause();
    }
}

int sent_signal(char *coord, pid_t pid)
{
    char a = coord[0];
    char b = coord[1];
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    signal.sa_handler = my_handler_sent;
    sent_signal_caractere(a, pid, signal);
    sent_signal_caractere(b, pid, signal);
    return (0);
}
