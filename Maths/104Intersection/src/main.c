/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for intersection
*/

#include "intersection.h"

int main(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        exit(0);
    }
    intersection(ac, av);
    return (0);
}
