/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** all usefull function for destroy
*/

#include "my_hunter.h"

void my_destroy(hunter_s *hunter, sfRenderWindow *window)
{
    sfSprite_destroy(hunter->s_duck);
    sfSprite_destroy(hunter->s_back);
    sfSprite_destroy(hunter->s_play);
    sfSprite_destroy(hunter->s_final);
    sfTexture_destroy(hunter->t_duck);
    sfTexture_destroy(hunter->t_back);
    sfTexture_destroy(hunter->t_play);
    sfTexture_destroy(hunter->t_final);
    sfText_destroy(hunter->text);
    sfText_destroy(hunter->text_score);
    sfText_destroy(hunter->text_final);
    sfClock_destroy(hunter->clock);
    sfRenderWindow_destroy(window);
}
