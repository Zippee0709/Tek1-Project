/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** all init function
*/

#include "trigo.h"

void my_init_value(Global_t *global, int ac, char **av)
{
    int i = 2;
    int j = 0;

    while (i < ac) {
        global->value[j] = atoi(av[i]);
        i++;
        j++;
    }
}

void my_init_global(Global_t *global, int ac, char **av)
{
    global->length = ac - 2;
    global->size = sqrtf(global->length);
    global->value = malloc(sizeof(float) * global->length);
    global->result = malloc(sizeof(float) * global->length);

    if (global->value == NULL || global->result == NULL)
        exit(EXIT_FAIL);
    my_init_value(global, ac, av);
}
