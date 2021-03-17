/*
** EPITECH PROJECT, 2019
** run.c
** File description:
** all usefull run function
*/

#include "my_defender.h"

void run_menu(s_game *game)
{
    analyse_event(game);
    draw_menu(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
}

void run_game_pause(s_game *game)
{
    sfBool var = sfKeyboard_isKeyPressed(sfKeyEscape);

    analyse_event(game);
    draw_game(game);
    sfRenderWindow_drawSprite(game->window, game->pause.sprite, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    if (var == 1 && game->status == PAUSE && game->is_reset == sfTrue) {
        game->status = GAME;
        game->escape = 0;
        game->is_reset = sfFalse;
    }
}

void run_game(s_game *game)
{
    analyse_event(game);
    draw_game(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    my_update_game(game);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && game->is_reset) {
        game->is_reset = sfFalse;
        game->status = PAUSE;
    }
}

void run_final_menu(s_game *game)
{
    sfVector2f score = {900, 510};
    char *str = my_int_convert_str(game->score);

    analyse_event(game);
    sfText_setPosition(game->text.score, score);
    sfRenderWindow_drawText(game->window, game->text.score, NULL);
    sfRenderWindow_drawSprite(game->window, game->final.sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->play_again.rect,
                                     NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    free(str);
}

void run_all(s_game *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
        game->is_reset = sfTrue;
    switch (game->status) {
    case MENU:
        run_menu(game);
        break;
    case GAME:
        run_game(game);
        break;
    case PAUSE:
        run_game_pause(game);
        break;
    case FINAL:
        run_final_menu(game);
        break;
    case EXIT:
        sfRenderWindow_close(game->window);
        break;
    }
}
