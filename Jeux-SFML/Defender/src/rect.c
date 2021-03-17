/*
** EPITECH PROJECT, 2019
** rect.c
** File description:
** rect.c
*/

#include "my_defender.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value)
            rect->left = 0;
    }
}

void my_sprite_move_rect(Dlist_node *sp, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.05) {
        move_rect(&sp->obj.rect, 80, 1440);
        sfClock_restart(clock);
    }
}
