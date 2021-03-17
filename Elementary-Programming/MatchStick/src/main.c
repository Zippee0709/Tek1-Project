/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for matchstick
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
    s_game game;

    if (ac != 3) {
        my_putstr_err("Invalid argument for lauch game\n");
        return (84);
    }
    else if (matchstick(&game, av) == 84)
        return (84);
    return (0);
}
