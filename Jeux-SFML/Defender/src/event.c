/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** all event function
*/

#include "my_defender.h"

void analyse_event(s_game *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event) == sfTrue) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (game->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(game);
    }
}
