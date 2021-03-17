/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** draw_sprites.c
*/

#include "my_rpg.h"

void draw_menu_sprites(window_t *screen, menu_t *menu)
{
    sfView_setCenter(screen->view, (sfVector2f){RES_X / 2., RES_Y / 2.});
    sfRenderWindow_setView(screen->window, screen->view);
    for (int i = 0; i < 5; i++) {
        screen->draw(screen->window, menu->bg[i].sprite, NULL);
        if (sfClock_getElapsedTime(menu->bg[i].clock).microseconds > 100000) {
            move_rect(&menu->bg[i].rect, i + 1, 544);
            sfSprite_setTextureRect(menu->bg[i].sprite, menu->bg[i].rect);
            sfClock_restart(menu->bg[i].clock);
        }
    }
    for (int i = 0; i < 4; i++)
        screen->draw(screen->window, menu->button[i].sprite, NULL);
    screen->draw(screen->window, menu->logo[0].sprite, NULL);
    screen->draw(screen->window, menu->logo[1].sprite, NULL);
}

void draw_pnj(rpg_t *rpg, sprite_t *pnj)
{
    rpg->screen.draw(rpg->screen.window, pnj->sprite, NULL);
    if (TALK == 0 || TALK == -10) {
        sfSprite_setPosition(rpg->dial.sprite, rpg->dial.vector);
        rpg->screen.draw(rpg->screen.window, rpg->dial.sprite, NULL);
    }
}

void draw_game_sprites(rpg_t *rpg, sprite_t player, sprite_t *pnj)
{
    sfVector2f scale = {1920., 1080.};

    for (int a = 0; rpg->map[a] != NULL; a++)
        for (int b = 0; rpg->map[a][b].tile != NULL; b++)
            rpg->screen.draw(rpg->screen.window, rpg->map[a][b].tile, NULL);
    rpg->screen.draw(rpg->screen.window, player.sprite, NULL);
    draw_pnj(rpg, pnj);
    rpg->screen.draw(rpg->screen.window, rpg->inv->sprite, NULL);
    if (rpg->quest_button == true)
        rpg->screen.draw(rpg->screen.window, rpg->quest[0].sprite, NULL);
    if (rpg->quest_infos == true)
        rpg->screen.draw(rpg->screen.window, rpg->quest[1].sprite, NULL);
}

void draw_pause_sprites(rpg_t *rpg)
{
    if (rpg->index != PAUSE)
        return;
    for (int i = 0; i != 5; i++)
        rpg->screen.draw(rpg->screen.window, rpg->pause[i].spr, NULL);
}

void draw_sprites(rpg_t *rpg, menu_t *menu, sprite_t *pnj)
{
    sfRenderWindow_clear(rpg->screen.window, sfBlack);
    if (rpg->index == MENU)
        draw_menu_sprites(&rpg->screen, menu);
    if (rpg->index == GAME || rpg->index == PAUSE) {
        draw_game_sprites(rpg, rpg->player, pnj);
        draw_enemies(&rpg->screen, rpg);
        draw_pause_sprites(rpg);
        /* draw_stat(&rpg->screen, rpg->player.stat); */
        transition(rpg->screen.window, &rpg->mist);
        shot_rainbow(&rpg->screen, rpg->player.sprite, rpg);
    }
    if (rpg->index == HTP)
        rpg->screen.draw(rpg->screen.window, rpg->htp.spr, NULL);
    for (particules_t *tmp = rpg->snow; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(rpg->screen.window, tmp->sprite, NULL);
    rpg->screen.draw(rpg->screen.window, rpg->cursor.pointer, NULL);
    sfRenderWindow_drawVertexArray(rpg->screen.window, rpg->cursor.trail, NULL);
    sfRenderWindow_drawVertexArray(rpg->screen.window, rpg->cursor.shape, NULL);
    sfRenderWindow_display(rpg->screen.window);
}
