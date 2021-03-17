/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** menu_fct.c
*/

#include "my_rpg.h"

void play_game(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
        rpg->screen.event.type == sfEvtMouseButtonReleased)
        rpg->index = GAME;
}

void load_game(rpg_t *rpg)
{
    return;
}

void exit_game(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
            rpg->screen.event.type == sfEvtMouseButtonReleased)
            sfRenderWindow_close(rpg->screen.window);
}

void help_game(rpg_t *rpg)
{
    return;
}
