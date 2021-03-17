/*
** EPITECH PROJECT, 2019
** manage_mouse.c
** File description:
** manage_mouse.c
*/

#include "my_defender.h"

void manage_tower_status(s_game *game)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(game->window);

    if (game->tower_status == 0) {
        game->tower_status = check_click_on_list(game, game->base_gr, m_pos);
        game->tower_status = check_click_on_tower(game, game->tower_map, m_pos);
    }
    check_tower_status(game, m_pos);
}

void manage_menu_click(s_game *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f max = game->play.pos;
    max.x = max.x + 300;
    max.y = max.y + 140;

    if (check_pos_value(mouse_pos, game->play.pos, max) == 1) {
        sfMusic_play(game->music.start);
        game->status = GAME;
    }
    max = game->exit.pos;
    max.x = max.x + 300;
    max.y = max.y + 140;
    if (check_pos_value(mouse_pos, game->exit.pos, max) == 1) {
        sfMusic_play(game->music.game_over);
        game->status = EXIT;
    }
}

void manage_final_click(s_game *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f min = (sfVector2f){11, 9};
    sfVector2f max = (sfVector2f){211, 98};

    if (check_pos_value(mouse_pos, min, max) == 1) {
        game->status = MENU;
    }
}

void manage_pause_click(s_game *game)
{
    manage_resume_click(game);
    manage_exit_click(game);
}

void manage_mouse_click(s_game *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        switch (game->status) {
            case MENU:
                manage_menu_click(game);
                break;
            case GAME:
                manage_tower_status(game);
                break;
            case PAUSE:
                manage_pause_click(game);
                break;
            case FINAL:
                manage_final_click(game);
                break;
        }
    }
}
