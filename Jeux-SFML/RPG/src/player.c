/*
** EPITECH PROJECT, 2019
** player.c
** File description:
** player.c
*/

#include "my_rpg.h"

void player_move_direction(sprite_t *spr, sfFloatRect m, char **c, sfVector2f s)
{
    int (*player_fct[4])(sprite_t *a, sfVector2f b, char **c, sfVector2f d);

    player_fct[0] = move_down;
    player_fct[1] = move_up;
    player_fct[2] = move_left;
    player_fct[3] = move_right;
    for (int a = 0; a ^ 4; a++)
        player_fct[a](spr, (sfVector2f){0, 0}, c, s);
}

void player_update(sprite_t *player, rpg_t *rpg)
{
    float spd = (!sfKeyboard_isKeyPressed(sfKeyLShift)) ? 3. : 7.;
    sfVector2f scale = {spd * (float)RES_X / 1920., spd * (float)RES_Y / 1080};

    if (rpg->index != GAME)
        return;
    player_move_direction(player, rpg->max, rpg->coll, scale);
    if (sfClock_getElapsedTime(player->clock).microseconds > 200000) {
        if ((sfKeyboard_isKeyPressed(sfKeyD) | sfKeyboard_isKeyPressed(sfKeyQ) |
            sfKeyboard_isKeyPressed(sfKeyZ) | sfKeyboard_isKeyPressed(sfKeyS)))
            move_rect(&player->rect, 32, 96);
        sfClock_restart(player->clock);
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->vector);
}
