/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** all usefull set function
*/

#include "my_hunter.h"

void my_respawn_bird(hunter_s *hunter)
{
    sfVector2f s_pos = sfSprite_getPosition(hunter->s_duck);

    if (s_pos.x > 1980) {
        my_set_pos(hunter);
        hunter->life = hunter->life - 1;
        if (hunter->life == 0)
            hunter->status = 2;
    }
}

void my_set_pos(hunter_s *hunter)
{
    hunter->s_pos.x = 0;
    hunter->p_pos.x = 860;
    hunter->p_pos.y = 700;
    srand(time(NULL));
    hunter->s_pos.y = rand() % 950;
    sfSprite_setPosition(hunter->s_duck, hunter->s_pos);
    sfSprite_setPosition(hunter->s_play, hunter->p_pos);
}

void my_set_score(hunter_s *hunter, sfText *text)
{
    char *str = my_int_convert_str(hunter->score);

    sfText_setString(text, str);
    free(str);
}
