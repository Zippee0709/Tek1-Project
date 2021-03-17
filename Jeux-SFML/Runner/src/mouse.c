/*
** EPITECH PROJECT, 2019
** mouse.c
** File description:
** mouse
*/

#include "runner.h"

void my_check_mouse_play(s_game *game, sfMouseButtonEvent mouse, sfVector2f sprite)
{
    int posx = sprite.x + 200;
    int posy = sprite.x + 75;

    if (mouse.x >= sprite.x && mouse.x <= posx &&
        mouse.y >= sprite.y && mouse.y <= posy)
        game->status = 1;
}

void manage_mouse_click(s_game *game)
{
    sfVector2f s_pos = {0, 0};

    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->status == 0) {
            s_pos = sfSprite_getPosition(game->play_bg.sprite);
            my_check_mouse_play(game, game->event.mouseButton, s_pos);
        }
    }
        
}
