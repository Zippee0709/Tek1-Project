/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** all usefull function about event
*/

#include "my_hunter.h"

void my_check_mouse_play(hunter_s *hunter, sfMouseButtonEvent mouse,
                         sfVector2f sprite)
{
    int posx = sprite.x + 200;
    int posy = sprite.y + 75;

    if (mouse.x >= sprite.x && mouse.x <= posx &&
        mouse.y >= sprite.y && mouse.y <= posy) {
        hunter->status = 1;
    }
}

void my_check_mouse_duck(hunter_s *hunter, sfMouseButtonEvent mouse,
                         sfVector2f sprite)
{
    int posx110 = sprite.x + 110;
    int posy110 = sprite.y + 110;

    if (mouse.x >= sprite.x && mouse.x <= posx110 &&
        mouse.y >= sprite.y && mouse.y <= posy110) {
        hunter->score = hunter->score + 1;
        hunter->move.x = hunter->move.x + 0.2;
        my_set_pos(hunter);
        my_set_score(hunter, hunter->text_score);
    }
}

void my_check_mouse_final(hunter_s *hunter, sfMouseButtonEvent mouse)
{
    if (mouse.x >= 692 && mouse.x <= 1162 &&
        mouse.y >= 696 && mouse.y <= 778) {
        init_struct_value(hunter);
    }
}

void manage_mouse_click(hunter_s *hunter)
{
    sfVector2f s_pos = {0, 0};

    if (hunter->event.mouseButton.button == sfMouseLeft) {
        if (hunter->status == 0) {
            s_pos = sfSprite_getPosition(hunter->s_play);
            my_check_mouse_play(hunter, hunter->event.mouseButton, s_pos);
        }
        else if (hunter->status == 1) {
            s_pos = sfSprite_getPosition(hunter->s_duck);
            my_check_mouse_duck(hunter, hunter->event.mouseButton, s_pos);
        }
        else
            my_check_mouse_final(hunter, hunter->event.mouseButton);
    }
}

void analyse_event(sfRenderWindow *window, hunter_s *hunter)
{
    if (sfRenderWindow_pollEvent(window, &hunter->event) == sfTrue) {
        if (hunter->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (hunter->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(hunter);
    }
}
