/*
** EPITECH PROJECT, 2019
** fill_tab.c
** File description:
** all usefull function for fill tab
*/

#include "my.h"
#include "matchstick.h"

void fill_first_or_last_line(s_game *game, int i)
{
    int j = 0;

    while (j != game->length) {
        game->map[i][j] = '*';
        j = j + 1;
    }
    game->map[i][j] = '\0';
}

void fill_other_line(s_game *game, int i, int space, int bar)
{
    int j = 0;

    while (j != game->length) {
        if (j == 0 || j == game->length - 1)
            game->map[i][j] = '*';
        else if (j > space && j < bar)
            game->map[i][j] = '|';
        else
            game->map[i][j] = ' ';
        j = j + 1;
    }
    game->map[i][j] = '\0';
}

void my_fill_tab(s_game *game)
{
    int i = 0;
    int space = game->size + 2 - 3;
    int bar = space + 2;

    while (i < game->size + 2) {
        if (i == 0 || i == game->size + 2 - 1)
            fill_first_or_last_line(game, i);
        else {
            fill_other_line(game, i, space, bar);
            space = space - 1;
            bar = bar + 1;
        }
        i = i + 1;
    }
    game->map[i] = NULL;
}
