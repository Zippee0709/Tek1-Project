/*
** EPITECH PROJECT, 2019
** run.c
** File description:
** run.c
*/

#include "runner.h"

void run_menu(sfRenderWindow *window, s_game *game)
{
    analyse_event(window, game);
    set_texture(game);
    set_texture_rect(game);
    draw_all_sprite(window, game);
    sfRenderWindow_drawSprite(window, game->play_bg.sprite, NULL);
    sfRenderWindow_display(window);
}

void run_game(sfRenderWindow *window, s_game *game)
{
    analyse_event(window, game);
    pending_game(window, game);
    game->score++;
}

void run_final(sfRenderWindow *window, s_game *game)
{
    analyse_event(window, game);
    sfRenderWindow_drawSprite(window, game->replay_bg.sprite, NULL);
    sfRenderWindow_display(window);
}
    
void main_run(sfRenderWindow *window, s_game *game)
{
    analyse_event(window, game);

    if (game->status == 0)
        run_menu(window, game);
    else if (game->status == 1) {
        analyse_map(game, &game->i);
        run_game(window, game);
    }
    else
        run_final(window, game);

    sfRenderWindow_clear(window, sfBlack);
}
