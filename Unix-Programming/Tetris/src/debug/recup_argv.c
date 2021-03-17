/*
** EPITECH PROJECT, 2019
** recup_argv.c
** File description:
** recup argv from user input
*/

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"
#include "my.h"

int recup_argv_switch(int opt, tetris_t *tetris)
{
    switch (opt) {
    case 't':
        tetris->opt->turn =
            (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);
        break;
    case 'd':
        tetris->opt->drop =
            (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);
        break;
    case 'q':
        tetris->opt->quit =
            (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);
        break;
    default:
        if (recup_argv_switch_flw(opt, tetris) == -1)
            return (-1);
    }
    return (0);
}

int check_if_it_only_number(char *optarg)
{
    for (int i = 0; optarg[i] != '\0'; i++) {
        if (optarg[i] < '0' || optarg[i] > '9') {
            return (-1);
        }
    }
    return (0);
}

int check_optarg(char *optarg)
{
    if (optarg == NULL)
        return (0);
    if (tigetstr(optarg) == (char *) -1 && my_strlen(optarg) > 1 &&
        check_if_it_only_number(optarg) == -1) {
        my_putstr_fd(2, "Error, only one char is accepted for key.\n");
        return (-1);
    }
    return (0);
}

int recup_argv_flw(struct option lg_opt[], int ac, char **av, tetris_t *tetris)
{
    int opt = 0;

    while ((opt = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", lg_opt, NULL))
            != -1) {
        if (check_optarg(optarg) == -1)
            return (-1);
        switch (opt) {
        case 'L':
            tetris->opt->level = my_getnbr(optarg);
            break;
        case 'l':
            tetris->opt->left =
                (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);
            break;
        default:
            if (recup_argv_switch(opt, tetris) == -1)
                return (-1);
        }
    }
    return 0;
}

int recup_argv(int ac, char **av, tetris_t *tetris)
{
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"level", optional_argument, NULL, 'L'},
        {"key-left", optional_argument, NULL, 'l'},
        {"key-right", optional_argument, NULL, 'r'},
        {"key-turn", optional_argument, NULL, 't'},
        {"key-drop", optional_argument, NULL, 'd'},
        {"key-quit", optional_argument, NULL, 'q'},
        {"key-pause", optional_argument, NULL, 'p'},
        {"map-size", optional_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {0, 0, 0, 0}
    };
    if (recup_argv_flw(long_options, ac, av, tetris) == -1)
        return -1;
    return (0);
}
