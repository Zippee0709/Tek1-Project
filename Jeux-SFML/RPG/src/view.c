/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** view.c
*/

#include "my_rpg.h"

sfFloatRect get_sizemap(char **map)
{
    int a;
    int b;
    sfFloatRect max = {0., 0., 0., 0.};

    for (a = 0; map[a] != NULL; a++) {
        for (b = 0; map[a][b] ^ '\n' && map[a][b]; b++);
        max.width = ((float)b > max.width) ? (float)b : max.width;
    }
    max.top = (float)RES_X / 2.;
    max.left = (float)RES_Y / 2.;
    max.width = max.width * (VALUE * (float)RES_X / 720.);
    max.height = (float)a * (VALUE * (float)RES_Y / 480.);
    return (max);
}

void new_place(rpg_t *rpg, sfVector2f pos)
{
    sfView_move(rpg->screen.view, pos);
    sfSprite_move(rpg->inv->sprite, pos);
    rpg->inv->origin.x += pos.x;
    rpg->inv->origin.y += pos.y;
    rpg->inv->pos.x += pos.x;
    rpg->inv->pos.y += pos.y;
    for (int a = 0; a ^ 5; a++) {
        rpg->pause[a].pos.x += pos.x;
        rpg->pause[a].pos.y += pos.y;
        sfSprite_setPosition(rpg->pause[a].spr, rpg->pause[a].pos);
    }
    rpg->screen.offset.x += pos.x;
    rpg->screen.offset.y += pos.y;
}

void update_view(rpg_t *rpg, sfVector2f pos, sfVector2f scle, sfFloatRect sz)
{
    sfVector2f size = {70. * (float)RES_X / 720., 50. * (float)RES_Y / 480.};

    if (fabs(sfView_getCenter(rpg->screen.view).x - pos.x) > size.x) {
        if (pos.x < sfView_getCenter(rpg->screen.view).x &&
            sfView_getCenter(rpg->screen.view).x > sz.top) {
            new_place(rpg, create_vector(-2., 0, scle));
        } else if (pos.x > sfView_getCenter(rpg->screen.view).x &&
            sfView_getCenter(rpg->screen.view).x < (sz.width - sz.top))
            new_place(rpg, create_vector(2., 0, scle));
    }
    if (fabs(sfView_getCenter(rpg->screen.view).y - pos.y) > size.y) {
        if (pos.y < sfView_getCenter(rpg->screen.view).y &&
            sfView_getCenter(rpg->screen.view).y > sz.left)
            new_place(rpg, create_vector(0, -2., scle));
        else if (pos.y > sfView_getCenter(rpg->screen.view).y &&
            sfView_getCenter(rpg->screen.view).y < (sz.height - sz.left))
            new_place(rpg, create_vector(0, 2., scle));
    }
    sfRenderWindow_setView(rpg->screen.window, rpg->screen.view);
}

void move_view(rpg_t *rpg)
{
    sfVector2f scale = {720., 480.};

    if (rpg->index != MENU)
        update_view(rpg, rpg->player.vector, scale, rpg->max);
}
