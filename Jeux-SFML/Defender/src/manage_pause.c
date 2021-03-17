/*
** EPITECH PROJECT, 2019
** manage_pause.c
** File description:
** manage_pause.c
*/

#include "my_defender.h"

void manage_resume_click(s_game *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f min = (sfVector2f){766, 275};
    sfVector2f max = (sfVector2f){1077, 578};

    if (check_pos_value(mouse_pos, min, max) == 1) {
        game->status = GAME;
    }

}

void manage_options_click(s_game *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f min = (sfVector2f){765, 439};
    sfVector2f max = (sfVector2f){1080, 577};

    if (check_pos_value(mouse_pos, min, max) == 1) {
        game->status = FINAL;
    }
}

void manage_exit_click(s_game *game)
{

    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f min = (sfVector2f){770, 614};
    sfVector2f max = (sfVector2f){1080, 750};

    if (check_pos_value(mouse_pos, min, max) == 1) {
        game->status = EXIT;
    }
}

