/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** all usefull event func
*/

#include "runner.h"

void event_jump(s_game *game)
{
    sfVector2f up_jump = {0, -6};
    sfVector2f dw_jump = {0, 6};

    if (game->jump >= 1 && game->jump <= 30) {
        sfSprite_move(game->sprite.sprite, up_jump);
        game->jump = game->jump + 1;
        return;
    }
    else if (game->jump >= 30 && game->jump <= 60) {
        sfSprite_move(game->sprite.sprite, dw_jump);
        game->jump = game->jump + 1;
        return;
    }
    game->jump = 0;
}

void analyse_event(sfRenderWindow *window, s_game *game)
{
    if (sfRenderWindow_pollEvent(window, &game->event) == sfTrue) {
	if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeySpace && game->jump == 0) {
            game->jump = 1;
        }
        if (game->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(game);
    }
}

void analyse_map(s_game *game, int *i)
{
    if ((game->map[*i] == '1' || game->map[*i] == '2' || game->map[*i] == '3')
        && (game->nb_zombie < 3)) {
        game->nb_zombie = game->nb_zombie + 1;
        *i = *i + 1;
    }
    else if (game->map[*i] == '\n')
        *i = 0;
    else
        *i = *i + 1;
}
