/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for
*/

#include "../include/my_defender.h"

int main(int ac, char **av)
{
    if (ac == 1)
        create_window();
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
            my_help();
    else
        my_putstr_err("Error :  invalid argument!\n");
    return (0);
}
