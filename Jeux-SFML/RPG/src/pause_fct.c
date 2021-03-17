/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause_fct.c
*/

#include "my_rpg.h"

int pause_new(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
        rpg->screen.event.type == sfEvtMouseButtonReleased) {
        sfRenderWindow_close(rpg->screen.window);
        return (my_rpg());
    }
    return (0);
}

int pause_continue(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
        rpg->screen.event.type == sfEvtMouseButtonReleased)
        rpg->index = GAME;
    return (0);
}

int pause_exit(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
        rpg->screen.event.type == sfEvtMouseButtonReleased)
        sfRenderWindow_close(rpg->screen.window);
    return (0);
}

int pause_option(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfRenderWindow_waitEvent(rpg->screen.window, &rpg->screen.event) &&
        rpg->screen.event.type == sfEvtMouseButtonReleased)
        rpg->index = HTP;
    return (0);
}
