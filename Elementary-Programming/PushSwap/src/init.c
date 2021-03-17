/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** all usefull init function
*/

#include "my.h"
#include "pushswap.h"

void help(void)
{
    my_putstr("USAGE : ./pushswap [nb1] [nb2] ...\n");
}

int my_init_index(char const *av)
{
    if (av[0] == '-' && av[1] == 'v')
        return (2);
    return (1);
}

int my_init_status(char const *av)
{
    if (av[0] == '-' && av[1] == 'v')
        return (1);
    return (0);
}
