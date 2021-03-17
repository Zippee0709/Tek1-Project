/*
** EPITECH PROJECT, 2019
** create_window.c
** File description:
** create_window.c
*/

#include "my_defender.h"

void my_calculate_fps(s_game *game)
{
    game->start = sfClock_getElapsedTime(game->clock);
    game->start_sec = game->start.microseconds / 1000000.0;
    game->fps++;

    if (game->start_sec > 1) {
        game->fps = 0;
        sfClock_restart(game->clock);
    }
}

void create_window(void)
{
    s_game game;

    init_game(&game);
    game.start = sfClock_getElapsedTime(game.clock);
    game.start_sec = game.start.microseconds / 1000000.0;
    sfRenderWindow_setFramerateLimit(game.window, 60);
    sfMusic_play(game.music.game);
    while (sfRenderWindow_isOpen(game.window) == sfTrue) {
        run_all(&game);
        my_calculate_fps(&game);
    }
    my_free_all(&game);
}
