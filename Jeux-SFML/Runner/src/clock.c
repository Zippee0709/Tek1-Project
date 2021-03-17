/*
** EPITECH PROJECT, 2019
** clock.c
** File description:
** all usefull function who use clock for set value
*/

#include "runner.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value)
            rect->left = 0;
    }
}

void move_background(s_game *game)
{
    move_rect(&game->sky_bg.rect, 1, 1920);
    move_rect(&game->cloud_bg.rect, 2, 1920);
    move_rect(&game->rock_bg.rect, 3, 1920);
    move_rect(&game->tree_bg.rect, 4, 1920);
}

void clock_background(s_game *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 100000.0;

    if (game->seconds > 0.3) {
        move_background(game);
        sfClock_restart(game->clock);
    }
}

void clock_sprite(s_game *game)
{
    game->time = sfClock_getElapsedTime(game->sclock);
    game->seconds = game->time.microseconds / 100000.0;

    if (game->seconds > 1) {
        move_rect(&game->sprite.rect, 100, 800);
        move_rect(&game->monster.rect, 100, 600);
        move_rect(&game->monster1.rect, 100, 600);
        move_rect(&game->monster2.rect, 100, 600);
        sfClock_restart(game->sclock);
    }
}
