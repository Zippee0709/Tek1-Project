/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for my sokoban project
*/

#include "sokoban.h"
#include "my.h"

int main(int ac, char **av)
{
    sokoban_s sokoban;

    help(ac, av);
    if (ac == 2) {
        my_sokoban(av, &sokoban);
        my_print_result(sokoban.status);
        return (sokoban.status);
    }
    else
        return (84);
}
