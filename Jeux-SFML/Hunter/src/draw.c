/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** all usefull func for draw
*/

#include "my_hunter.h"

void draw_menu(sfRenderWindow *window, hunter_s *hunter)
{
    sfRenderWindow_drawSprite(window, hunter->s_back, NULL);
    sfRenderWindow_drawSprite(window, hunter->s_play, NULL);
}

void draw_sprite(sfRenderWindow *window, hunter_s *hunter)
{
    sfRenderWindow_drawSprite(window, hunter->s_back, NULL);
    sfRenderWindow_drawSprite(window, hunter->s_duck, NULL);
    sfRenderWindow_drawText(window, hunter->text, NULL);
    sfRenderWindow_drawText(window, hunter->text_score, NULL);
}

void draw_final(sfRenderWindow *window, hunter_s *hunter)
{
    sfRenderWindow_drawSprite(window, hunter->s_back, NULL);
    sfRenderWindow_drawSprite(window, hunter->s_final, NULL);
    sfRenderWindow_drawText(window, hunter->text_final, NULL);
}
