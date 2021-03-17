/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** transition.c
*/

#include "my_rpg.h"

void transition(sfRenderWindow *window, sprite_t *mist)
{
    if (mist->rect.left == 0)
        return;
    if (sfClock_getElapsedTime(mist->clock).microseconds > 40000) {
        mist->rect.left -= 640;
        sfClock_restart(mist->clock);
    }
    sfSprite_setTextureRect(mist->sprite, mist->rect);
    sfRenderWindow_drawSprite(window, mist->sprite, NULL);
}

int create_transition(sprite_t *mist)
{
    float x = 1.2 * RES_X / 720;
    float y = 2.0 * RES_Y / 480;
    sfVector2f scale = {720., 480.};

    mist->create_sprite = create_sprite;
    mist->create_rect = create_rect;
    mist->create_vector = create_vector;
    mist->sprite = mist->create_sprite(&mist->texture, TRANSITION, scale);
    if (!mist->sprite)
        return (FAILURE);
    mist->rect = mist->create_rect(0, 14080, 640, 360);
    mist->clock = sfClock_create();
    sfSprite_setScale(mist->sprite, (sfVector2f){x, y});
    return (SUCCESS);
}
