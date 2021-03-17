/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
*/

#include "bombyx.h"

void init_global(global_t *global, int ac, char **av)
{
    global->value = atof(av[1]);
    if (ac == 3) {
        global->status = 0;
        global->mul = atof(av[2]);
    }
    else if (ac == 4) {
        global->status = 1;
        global->mul = atof(av[2]);
        global->max = atof(av[3]);
    }
}
