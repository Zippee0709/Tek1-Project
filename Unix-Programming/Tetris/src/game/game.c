/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game.c
*/

#include "my.h"
#include "tetris.h"

void my_event(game_t *game, int action)
{
    shape_t tmp = my_copy_shape(game->current);
    game->tmp = my_strcpy_tab(game->tmp, game->map);

    if (move_down(game, action, tmp) == 1)
        return;
    if (move_left(game, action, tmp) == 1)
        return;
    if (move_right(game, action, tmp) == 1)
        return;
    if (move_rotate(game, action, tmp) == 1)
        return;
}

void my_main_game(game_t *game, tetris_t *tetris)
{
    (void)tetris;
    while (game->ch != tetris->opt->quit[0]) {
        my_event(game, game->ch);
        my_print_game_map(game->tmp, game->x);
        game->ch = getch();
        clear();
        refresh();
    }
}

void my_tetris(tetris_t *tetris)
{
    game_t game;

    my_init_game(&game, tetris);
    my_main_game(&game, tetris);
}
