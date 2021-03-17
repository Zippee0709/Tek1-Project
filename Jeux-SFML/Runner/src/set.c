/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** all usefull set function
*/

#include "runner.h"

sfIntRect my_set_rect(int a, int b, int c, int d)
{
    sfIntRect rect;

    rect.left = a;
    rect.top = b;
    rect.width = c;
    rect.height = d;
    return (rect);
}

void set_all_rect(s_game *game)
{
    game->sky_bg.rect = my_set_rect(0, 0, 1920, 1080);
    game->tree_bg.rect = my_set_rect(0, 0, 1920, 1080);
    game->cloud_bg.rect = my_set_rect(0, 0, 1920, 1080);
    game->rock_bg.rect = my_set_rect(0, 0, 1920, 1080);
    game->sprite.rect = my_set_rect(0, 0, 100, 95);
    game->monster.rect = my_set_rect(0, 0, 100, 95);
    game->monster1.rect = my_set_rect(0, 0, 100, 95);
    game->monster2.rect = my_set_rect(0, 0, 100, 95);
}

void set_texture(s_game *game)
{
    sfSprite_setTexture(game->sky_bg.sprite, game->sky_bg.texture, sfTrue);
    sfSprite_setTexture(game->tree_bg.sprite, game->tree_bg.texture, sfTrue);
    sfSprite_setTexture(game->cloud_bg.sprite, game->cloud_bg.texture, sfTrue);
    sfSprite_setTexture(game->replay_bg.sprite, game->replay_bg.texture, sfTrue);
    sfSprite_setTexture(game->play_bg.sprite, game->play_bg.texture, sfTrue);
    sfSprite_setTexture(game->sprite.sprite, game->sprite.texture, sfTrue);
    sfSprite_setTexture(game->monster.sprite, game->monster.texture, sfTrue);
    sfSprite_setTexture(game->monster1.sprite, game->monster1.texture, sfTrue);
    sfSprite_setTexture(game->monster2.sprite, game->monster2.texture, sfTrue);
}

void set_texture_rect(s_game *game)
{
    sfSprite_setTextureRect(game->sky_bg.sprite, game->sky_bg.rect);
    sfSprite_setTextureRect(game->tree_bg.sprite, game->tree_bg.rect);
    sfSprite_setTextureRect(game->cloud_bg.sprite, game->cloud_bg.rect);
    sfSprite_setTextureRect(game->rock_bg.sprite, game->rock_bg.rect);
    sfSprite_setTextureRect(game->sprite.sprite, game->sprite.rect);
    sfSprite_setTextureRect(game->monster.sprite, game->monster.rect);
    sfSprite_setTextureRect(game->monster1.sprite, game->monster1.rect);
    sfSprite_setTextureRect(game->monster2.sprite, game->monster2.rect);
}

void set_all_position(s_game *game)
{
    sfSprite_setPosition(game->sprite.sprite, game->sprite.pos);
    sfSprite_setPosition(game->play_bg.sprite, game->play_bg.pos);
    sfSprite_setPosition(game->monster.sprite, game->monster.pos);
    sfSprite_setPosition(game->monster1.sprite, game->monster1.pos);
    sfSprite_setPosition(game->monster2.sprite, game->monster2.pos);
}
