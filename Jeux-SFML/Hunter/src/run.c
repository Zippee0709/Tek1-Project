/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** all usefull run func
*/

#include "my_hunter.h"

void run_menu(sfRenderWindow *window, hunter_s *hunter)
{
    analyse_event(window, hunter);
    draw_menu(window, hunter);
    sfRenderWindow_display(window);
}

void run_game_func(sfRenderWindow *window, hunter_s *hunter)
{
    analyse_event(window, hunter);
    draw_sprite(window, hunter);
    sfRenderWindow_display(window);
    my_clock(hunter);
    sfSprite_move(hunter->s_duck, hunter->move);
    my_respawn_bird(hunter);
}

void run_final_menu(sfRenderWindow *window, hunter_s *hunter)
{
    my_set_score(hunter, hunter->text_final);
    draw_final(window, hunter);
    sfRenderWindow_display(window);
}

void main_run(sfRenderWindow *window, hunter_s *hunter)
{
    analyse_event(window, hunter);

    if (hunter->status == 0)
        run_menu(window, hunter);
    else if (hunter->status == 1)
        run_game_func(window, hunter);
    else
        run_final_menu(window, hunter);

    sfRenderWindow_clear(window, sfBlack);
}
