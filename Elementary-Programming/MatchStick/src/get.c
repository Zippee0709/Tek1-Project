/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** all usefull function for get something
*/

#include "my.h"
#include "matchstick.h"

int my_get_line(s_game *game)
{
    game->user_line = my_getnbr(game->s);
    free(game->s);

    if (game->user_line >= 1 && game->user_line <= game->size)
        return (game->user_line);
    else if (game->user_line == -1)
        my_putstr_err("Error : invalid input (positive number expected)\n");
    else
        my_putstr_err("Error : this line is out of range\n");
    return (-1);
}

int my_get_last_stick_pos(char **map, int line)
{
    int i = 0;
    int k = 0;

    while (map[line][i] != '\0') {
        if (map[line][i] == '|')
            k = i;
        i = i + 1;
    }
    return (k);
}

int my_get_max_stick(char **map, int line)
{
    int i = 0;
    int nb = 0;

    while (map[line][i] != '\0') {
        if (map[line][i] == '|')
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}

int my_get_stick(s_game *game)
{
    game->user_stick = my_getnbr(game->s);
    free(game->s);
    int max_stick = my_get_max_stick(game->map, game->user_line);

    if (game->user_stick >= 1 && game->user_stick <= max_stick)
        return (game->user_stick);
    else if (game->user_stick > game->nb_stick) {
        my_putstr_err("Error : you cannot remove more than ");
        my_putnbr_err(game->nb_stick);
        my_putstr_err(" matches pers turn\n");
    }
    else
        my_putstr_err("Error : no enough matches on this line\n");
    return (-1);
}
