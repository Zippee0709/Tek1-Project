/*
** EPITECH PROJECT, 2019
** search.c
** File description:
** search.c
*/

#include "my.h"
#include "matchstick.h"

int my_search_nb_stick_on_map(char **map, int nb)
{
    int i = 0;
    int max_stick = 0;

    while (map[i] != NULL) {
        max_stick = my_get_max_stick(map, i);
        if (max_stick >= nb)
            return (i);
        i = i + 1;
    }
    return (0);
}

void my_ai_update(s_game *game)
{
    int i = 0;
    int pos = my_get_last_stick_pos(game->map, game->ai_line);

    while (i < game->ai_stick) {
        game->map[game->ai_line][pos] = ' ';
        pos = pos - 1;
        i = i + 1;
    }
}

int my_check_odd(s_game *game, s_ai *ai)
{
    int i = 0;
    int nb = 0;

    while (ai->tab[i] != '\0') {
        if (ai->tab[i] > 0 && ai->tab[1] % 2 == 0)
            my_ai_take_stick(game, i);
        i = i + 1;
    }
    return (nb);
}
