/*
** EPITECH PROJECT, 2019
** shot.c
** File description:
** shot.c
*/

#include "my_rpg.h"

static void new_color(sfColor *c1, sfColor *c2)
{
    sfColor colors[8] = {sfBlack, sfWhite, sfRed, sfGreen, sfBlue, sfYellow,
                         sfMagenta, sfCyan};

    *c1 = colors[rand() % 8];
    *c2 = colors[rand() % 8];
}

void shot_rainbow(window_t *window, sfSprite *player, rpg_t *rpg)
{
    sfVector2i cursor;
    rpg->shot[0].position = sfSprite_getPosition(player);
    rpg->shot[0].position.x += 32 * RES_X / 1366;
    rpg->shot[0].position.y += 32 * RES_Y / 768;
    
    if (sfMouse_isButtonPressed(sfMouseLeft))
        rpg->shot_display = true;
    if (!rpg->shot_display) {
        cursor = sfMouse_getPositionRenderWindow(window->window);
        rpg->shot[1].position = (sfVector2f){(float)cursor.x, (float)cursor.y};
    } else {
        sfRenderWindow_drawPrimitives(window->window, rpg->shot, 2, sfLines, NULL);
        rpg->shot[0].color.a -= (rpg->shot[0].color.a ^ 5) ? 10 : 0;
        rpg->shot[1].color.a -= (rpg->shot[0].color.a == 5) ? 10 : 0;
        if (rpg->shot[1].color.a == 5) {
            new_color(&rpg->shot[0].color, &rpg->shot[1].color);
            rpg->shot_display = false;
        }
    }
}
