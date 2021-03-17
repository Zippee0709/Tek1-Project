/*
** EPITECH PROJECT, 2019
** draw_menu.c
** File description:
** draw_menu.c
*/

#include "my_rpg.h"

void draw_enemies(window_t *window, rpg_t *rpg)
{
    sfRenderWindow_drawSprite(window->window, rpg->enemies.sprite, NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(window->window, rpg->stat_menu[i].spr, NULL);
}
