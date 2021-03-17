/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** events.c
*/

#include "my_rpg.h"
#include <stdio.h>

void change_screen(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyDelete))
        sfRenderWindow_close(rpg->screen.window);
    if (rpg->index == HTP && event.type == sfEvtKeyReleased
        && event.key.code == sfKeyEscape)
        rpg->index = MENU;
    if (rpg->index == GAME && event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyEscape)
            rpg->index = PAUSE;
        if (event.key.code == sfKeyM)
            rpg->index = MENU;
    } else if (rpg->index == PAUSE && event.type == sfEvtKeyReleased
            && event.key.code == sfKeyEscape)
        rpg->index = GAME;
}

void menu_events(rpg_t *rpg, menu_t *menu)
{
    sfFloatRect cursor = sfSprite_getGlobalBounds(rpg->cursor.pointer);
    sfFloatRect button = {0, 0, 0, 0};

    if (rpg->index != MENU)
        return;
    for (int a = 0; a ^ 4; a++) {
        button = sfSprite_getGlobalBounds(menu->button[a].sprite);
        if (sfFloatRect_intersects(&cursor, &button, NULL) == sfTrue)
            menu->ptr_fct[a](rpg);
    }
}

void manage_game_events(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyI) {
        rpg->inv->active = (rpg->inv->active == false) ? true : false;
        if (rpg->inv->active == true)
            return (sfSprite_setPosition(rpg->inv->sprite, rpg->inv->pos));
        sfSprite_setPosition(rpg->inv->sprite, rpg->inv->origin);
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyW)
        if (screen_shot((const sfRenderWindow *)rpg->screen.window) < 0)
            write(2, "The image wasn't saved.\n", 24);
    if (rpg->quest_button == true && rpg->quest_infos == false &&
        event.type == sfEvtKeyReleased && event.key.code == sfKeyJ)
        rpg->quest_infos = true;
    else if (rpg->quest_button == true && rpg->quest_infos == true &&
            event.type == sfEvtKeyReleased && event.key.code == sfKeyJ)
        rpg->quest_infos = false;
}

void manage_pause_events(rpg_t *rpg)
{
    sfFloatRect mouse = sfSprite_getGlobalBounds(rpg->cursor.pointer);
    sfFloatRect button = {0., 0., 0., 0.};
    sfVector2f pos = {0., 0.};
    int (*ptr_fct[4])(rpg_t *rpg);

    ptr_fct[0] = pause_new;
    ptr_fct[1] = pause_continue;
    ptr_fct[2] = pause_option;
    ptr_fct[3] = pause_exit;
    for (int i = 1; i ^ 5; i++) {
        button = sfSprite_getGlobalBounds(rpg->pause[i].spr);
        pos = sfSprite_getPosition(rpg->pause[i].spr);
        pos.y -= (rpg->pause[i].pos.y - pos.y < 8. * RES_Y / 480.) ? 1 : 0;
        if (sfFloatRect_intersects(&mouse, &button, NULL) == sfTrue) {
            sfSprite_setPosition(rpg->pause[i].spr, pos);
            ptr_fct[i - 1](rpg);
        } else
            sfSprite_setPosition(rpg->pause[i].spr, rpg->pause[i].pos);
    }
}

void manage_events(rpg_t *rpg, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(rpg->screen.window, &rpg->screen.event)) {
        change_screen(rpg, rpg->screen.event);
        menu_events(rpg, menu);
        if (rpg->index == GAME)
            manage_game_events(rpg, rpg->screen.event);
        if (rpg->index == PAUSE)
            manage_pause_events(rpg);
    }
    move_view(rpg);
    player_update(&rpg->player, rpg);
    enemies_update(rpg);
}
