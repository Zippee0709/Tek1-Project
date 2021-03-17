/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of navy
*/

#include "my.h"
#include "navy.h"

int main(int ac, char **av)
{
    int status = 0;

    if (ac > 3 || ac == 1) {
        my_putstr_fd(2, "Error, with arguments.\n");
        return (84);
    }
    if (ac == 2) {
        if ((status = player_one(av[1], status)) == -1)
            return (84);
    }
    if (ac == 3) {
        if ((status = player_two(my_getnbr(av[1]), av[2])) == -1)
            return (84);
    }
    return (status);
}
