/*
** EPITECH PROJECT, 2019
** enemies_update.c
** File description:
** enemies_update.c
*/

#include "my_rpg.h"

static void move_rect_top(sfIntRect *rect, int offset, int max)
{
    rect->top += offset;
    if (rect->top >= max)
        rect->top = 0;
}

static void enemies_move_direction(sprite_t *sprite, sprite_t *player)
{
    float spd = 2;
    sfVector2f scale = {spd * (float)RES_X / 1920., spd * (float)RES_Y / 1080};

    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sprite->rect.left = 48;
        sprite->vector.y -= scale.y;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sprite->rect.left = 144;
        sprite->vector.y += scale.y;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sprite->rect.left = 0;
        sprite->vector.x += scale.x;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sprite->rect.left = 96;
        sprite->vector.x -= scale.x;
    }
}

static void enemies_died(sprite_t *sprite, sprite_t *player)
{
    sfVector2f scale = {2 * (float)RES_X / 1920., 2 * (float)RES_Y / 1080};

    if (sprite->vector.x < player->vector.x - 30) {
        sprite->vector.x += scale.x;
        sprite->rect.left = 0;
    }
    if (sprite->vector.x > player->vector.x + 30) {
        sprite->vector.x -= scale.x;
        sprite->rect.left = 96;
    }
    if (sprite->vector.y < player->vector.y - 30) {
        sprite->vector.y += scale.y;
        sprite->rect.left = 144;
    }
    if (sprite->vector.y > player->vector.y + 30) {
        sprite->vector.y -= scale.y;
        sprite->rect.left = 48;
    }
}

void enemies_update(rpg_t *rpg)
{
    if (sfClock_getElapsedTime(rpg->enemies.clock).microseconds > 200000) {
        move_rect_top(&rpg->enemies.rect, 24, 120);
        sfClock_restart(rpg->enemies.clock);
    }
    enemies_move_direction(&rpg->enemies, &rpg->player);
    enemies_died(&rpg->enemies, &rpg->player);
    sfSprite_setTextureRect(rpg->enemies.sprite, rpg->enemies.rect);
    sfSprite_setPosition(rpg->enemies.sprite, rpg->enemies.vector);
}
