/*
** EPITECH PROJECT, 2019
** recup_argv_flw.c
** File description:
** recup argv
*/

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"
#include "my.h"

int recup_argv_switch_next(int opt, tetris_t *tetris)
{
    switch (opt) {
    case 'p':
        tetris->opt->pause =
            (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);;
        break;
    case 'r':
        tetris->opt->right =
            (tigetstr(optarg) == (char *)-1) ? optarg : tigetstr(optarg);
        break;
    case 'w':
        tetris->opt->next = false;
        break;
    default:
        return (-1);
    }
    return (0);
}

int recup_argv_switch_flw(int opt, tetris_t *tetris)
{
    static int counter = 0;

    switch (opt) {
    case 'm':
        (counter == 1 ? (tetris->opt->size.y = my_getnbr(optarg)) :
        (tetris->opt->size.x = my_getnbr(optarg)));
        counter++;
        break;
    case 'D':
        tetris->debug = true;
        break;
    case 'h':
        tetris->help = true;
        break;
    default:
        if (recup_argv_switch_next(opt, tetris) == -1)
            return (-1);
    }
    return (0);
}
