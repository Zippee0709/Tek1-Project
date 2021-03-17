/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** func.c
*/

#include "my_hunter.h"

void set_sprite_texture(hunter_s *hunter)
{
    sfSprite_setTexture(hunter->s_duck, hunter->t_duck, sfTrue);
    sfSprite_setTexture(hunter->s_back, hunter->t_back, sfTrue);
    sfSprite_setTexture(hunter->s_play, hunter->t_play, sfTrue);
    sfSprite_setTexture(hunter->s_final, hunter->t_final, sfTrue);
}

void set_rect(hunter_s *hunter)
{
    sfSprite_setTextureRect(hunter->s_duck, hunter->rect_duck);
}

void mouv_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value)
            rect->left = 0;
    }
}

void my_clock(hunter_s *hunter)
{
    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->second = hunter->time.microseconds / 1000000.0;

    if (hunter->second > 0.5) {
        mouv_rect(&hunter->rect_duck, 110, 330);
        set_rect(hunter);
        sfClock_restart(hunter->clock);
    }
}
