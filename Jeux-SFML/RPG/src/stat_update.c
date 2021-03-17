/*
** EPITECH PROJECT, 2019
** stat_update.c
** File description:
** stat_update.c
*/

#include "my_rpg.h"

static float calc_bar_scale(int hp, int max_hp)
{
    float res = hp * 100 / max_hp * 0.01 * 0.2;

    if (res < 0)
        res = 0;
    return (res);
}

void update_stat_menu_status(rpg_t *rpg, stat_t stat)
{
    float scale = calc_bar_scale(stat.hp, stat.max_hp);
    sfVector2f size = {scale * (float)RES_X / 720., 0.2 * (float)RES_Y / 480.};

    sfSprite_setScale(rpg->stat_menu[3].spr, size);
    scale = calc_bar_scale(stat.attack, stat.max_attack);
    size = (sfVector2f){scale * (float)RES_X / 720, 0.2 * (float)RES_Y / 480};
    sfSprite_setScale(rpg->stat_menu[4].spr, size);
    scale = calc_bar_scale(stat.defense, stat.max_defense);
    size = (sfVector2f){scale * (float)RES_X / 720, 0.2 * (float)RES_Y / 480};
    sfSprite_setScale(rpg->stat_menu[5].spr, size);
}
