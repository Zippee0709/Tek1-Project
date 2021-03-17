/*
** EPITECH PROJECT, 2019
** button_scale.c
** File description:
** button_scale.c
*/

#include "my_rpg.h"

void cursor_move_on_menu(cursor_t *cursor, menu_t *men)
{
    sfFloatRect p_rect = sfSprite_getGlobalBounds(cursor->pointer);
    sfFloatRect b_rect = {0, 0, 0, 0};
    sfVector2f pos;
    sfVector2f sc[2] = {{2.0 * (float)RES_X / 720., 2.0 * (float)RES_Y / 480.},
                        {2.2 * (float)RES_X / 720., 2.2 * (float)RES_Y / 480.}};

    for (int i = 0; i < 4; i++) {
        b_rect = sfSprite_getGlobalBounds(men->button[i].sprite);
        if (sfFloatRect_intersects(&b_rect, &p_rect, NULL) == sfTrue) {
            sfSprite_setScale(men->button[i].sprite, sc[1]);
            pos = men->button[i].vector;
            pos.x -= (10. * (float)RES_X / 720.);
            sfSprite_setPosition(men->button[i].sprite, pos);
        } else if (sfSprite_getScale(men->button[i].sprite).x > 2.0) {
            sfSprite_setScale(men->button[i].sprite, sc[0]);
            sfSprite_setPosition(men->button[i].sprite, men->button[i].vector);
        }
    }
}
