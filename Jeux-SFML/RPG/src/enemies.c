/*
** EPITECH PROJECT, 2019
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

int create_enemies(sprite_t *sprite)
{
    sfVector2f scale = {1920.0, 1080.0};
    sfVector2f size = {4.5 * (float)RES_X / 1920., 4.5 * (float)RES_Y / 1080.};

    init_fctptr(sprite);
    sprite->sprite = sprite->create_sprite(&sprite->texture, SKELETON_1, scale);
    if (!sprite->sprite)
        return (FAILURE);
    sprite->rect = sprite->create_rect(0, 0, 24, 24);
    sprite->vector = sprite->create_vector(-1000, 2000, scale);
    sprite->clock = sfClock_create();
    sprite->stat = init_stat(50, 50, 5, 5);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
    sfSprite_setScale(sprite->sprite, size);
    return (SUCCESS);
}
