/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for my_runner
*/

#include "runner.h"

void help(void)
{
    my_putstr("Finite runner create with CSFML.\n\n");
    my_putstr("Usage\n ./my_runner map.txt\n\n");
    my_putstr("Options\n -i \t lauch the game in infinity mode\n");
    my_putstr(" -h \t print the usage and quit\n");
    my_putstr("User interactions\n Space_key \t jump\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_putstr_err("Error : please insert a map !\n");
        return (84);
    }
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    else if (ac == 2 && create_window(av[1]) == -1)
        return (84);
    return (0);
}
