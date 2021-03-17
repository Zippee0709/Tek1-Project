/*
** EPITECH PROJECT, 2019
** init_stat.c
** File description:
** init_stat.c
*/

#include "my_rpg.h"

stat_t init_stat(int hp, int max_hp, int attack, int defense)
{
    stat_t stat = {hp, max_hp, attack, defense, 100, 100, 1};
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {0.5 * (float)RES_X / 720., 0.5 * (float)RES_Y / 480.};

    stat.bg.spr = create_sprite(&stat.bg.tex, STAT_MENU_BG, scale);
    stat.bg.rect = create_rect(76, 397, 503, 602);
    stat.bg.pos = create_vector(625, 300, scale);
    sfSprite_setTextureRect(stat.bg.spr, stat.bg.rect);
    sfSprite_setPosition(stat.bg.spr, stat.bg.pos);
    sfSprite_setScale(stat.bg.spr, size);
    return (stat);
}

static int create_stat_menu(object_t *sprite, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {0.2 * (float)RES_X / 720., 0.2 * (float)RES_Y / 480.};

    sprite->spr = create_sprite(&sprite->tex, STAT_MENU, scale);
    if (!sprite->spr)
        return (FAILURE);
    sprite->rect = create_rect(top, 0, 410, 95);
    sprite->pos = create_vector(x, y, scale);
    sfSprite_setTextureRect(sprite->spr, sprite->rect);
    sfSprite_setPosition(sprite->spr, sprite->pos);
    sfSprite_setScale(sprite->spr, size);
    return (SUCCESS);
}

static int create_stat_menu_shape(object_t *sprite, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {0.2 * (float)RES_X / 720., 0.2 * (float)RES_Y / 480.};

    sprite->spr = create_sprite(&sprite->tex, STAT_MENU, scale);
    if (!sprite->spr)
        return (FAILURE);
    sprite->rect = create_rect(top, 444, 282, 34);
    sprite->pos = create_vector(x, y, scale);
    sfSprite_setTextureRect(sprite->spr, sprite->rect);
    sfSprite_setPosition(sprite->spr, sprite->pos);
    sfSprite_setScale(sprite->spr, size);
    return (SUCCESS);
}

int load_stat_menu(rpg_t *rpg)
{
    rpg->stat_menu = malloc(sizeof(object_t) * (6));

    if (rpg->stat_menu == NULL)
        return (FAILURE);
    if ((create_stat_menu(&rpg->stat_menu[0], 0, 50, 1020) |
        create_stat_menu(&rpg->stat_menu[1], 95, 275, 1020) |
        create_stat_menu(&rpg->stat_menu[2], 190, 500, 1020) |
        create_stat_menu_shape(&rpg->stat_menu[3], 29, 106, 1032) |
        create_stat_menu_shape(&rpg->stat_menu[4], 124, 331, 1032) |
        create_stat_menu_shape(&rpg->stat_menu[5], 217, 556, 1032)) == FAILURE)
        return (FAILURE);
    update_stat_menu_status(rpg, rpg->player.stat);
    return (SUCCESS);
}
