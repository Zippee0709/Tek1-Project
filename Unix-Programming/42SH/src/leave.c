/*
** EPITECH PROJECT, 2019
** leave.c
** File description:
** leave handle
*/

#include "minishell.h"

static int check_exit(char *command)
{
    int ok = 1;

    if (command[0] == 'e' && command[1] == 'x' &&
        command[2] == 'i' && command[3] == 't')
        ok = 0;
    else
        return 0;
    if (command[4] == '\0')
        return 1;
    if (ok == 0 && command[4] == ' ') {
        for (int i = 4; command[i] != '\0'; i++) {
            if (command[i] == ' ')
                return 1;
        }
    }
    return 0;
}

void quit(char *command)
{
    if (check_exit(command) == 1) {
        my_putstr("exit\n");
        exit(0);
    }
}

