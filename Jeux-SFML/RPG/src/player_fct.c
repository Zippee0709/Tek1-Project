/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_fct.c
*/

#include "my_rpg.h"

int move_down(sprite_t *player, sfVector2f blck, char **coll, sfVector2f scale)
{
    int x = (int)(player->vector.x / (VALUE * RES_X / 720.));
    int y = (int)(player->vector.y / (VALUE * RES_Y / 480.));

    if (sfKeyboard_isKeyPressed(sfKeyS))
        if (coll[++y] && coll[y][x] == '0') {
            player->rect.top = 0;
            player->vector.y += scale.y;
        }
}

int move_up(sprite_t *player, sfVector2f blck, char **coll, sfVector2f scale)
{
    int x = (int)(player->vector.x / (VALUE * RES_X / 720.));
    int y = (int)(player->vector.y / (VALUE * RES_Y / 480.));

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        if (y >= 0 && (coll[y][x] == '0' || coll[y][x] == '\n')) {
            player->rect.top = 96;
            player->vector.y -= scale.y;
        }
}

int move_left(sprite_t *player, sfVector2f blck, char **coll, sfVector2f scale)
{
    int x = (int)(player->vector.x / (VALUE * RES_X / 720.));
    int y = (int)(player->vector.y / (VALUE * RES_Y / 480.));

    if (sfKeyboard_isKeyPressed(sfKeyQ) && y != -1)
        if (x >= 0 && (coll[y][x - 1] == '0' || coll[y][x - 1] == '\n')) {
            player->rect.top = 32;
            player->vector.x -= scale.x;
        }
}

int move_right(sprite_t *player, sfVector2f blck, char **coll, sfVector2f scale)
{
    int x = (int)(player->vector.x / (VALUE * RES_X / 720.));
    int y = (int)(player->vector.y / (VALUE * RES_Y / 480.));

    if (sfKeyboard_isKeyPressed(sfKeyD) && y != -1)
        if (coll[y][x] && (coll[y][x] == '0' || coll[y][x] == '\n')) {
            player->rect.top = 64;
            player->vector.x += scale.x;
        }
}
