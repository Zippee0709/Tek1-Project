/*
** EPITECH PROJECT, 2019
** destroy.c
** File description:
** all usefull function for free content
*/

#include "runner.h"

void destroy_sprite(s_game *game)
{
    sfSprite_destroy(game->sky_bg.sprite);
    sfSprite_destroy(game->tree_bg.sprite);
    sfSprite_destroy(game->cloud_bg.sprite);
    sfSprite_destroy(game->rock_bg.sprite);
    sfSprite_destroy(game->sprite.sprite);
    sfSprite_destroy(game->monster.sprite);
}

void destroy_texture(s_game *game)
{
    sfTexture_destroy(game->sky_bg.texture);
    sfTexture_destroy(game->tree_bg.texture);
    sfTexture_destroy(game->cloud_bg.texture);
    sfTexture_destroy(game->rock_bg.texture);
    sfTexture_destroy(game->sprite.texture);
    sfTexture_destroy(game->monster.texture);
}

void destroy_all(sfRenderWindow *window, s_game *game)
{
    destroy_sprite(game);
    destroy_texture(game);
    sfClock_destroy(game->clock);
    sfClock_destroy(game->sclock);
    sfClock_destroy(game->jclock);
    sfRenderWindow_destroy(window);
}
