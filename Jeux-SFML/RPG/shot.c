/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow *relativeTo);
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow *renderWindow);

void new_color(sfColor *c1, sfColor *c2)
{
    sfColor colors[8] = {sfBlack, sfWhite, sfRed, sfGreen, sfBlue, sfYellow,
                         sfMagenta, sfCyan};

    *c1 = colors[rand() % 8];
    *c2 = colors[rand() % 8];
}

int main(void)
{
    sfVector2i cursor;
    bool display = false;
    sfVertex shot[2] = {{(sfVector2f){0., 0.}, sfBlue, (sfVector2f){0.0, 0.0}},
                        {(sfVector2f){0., 0.}, sfRed, (sfVector2f){0.0, 0.0}}};
    sfEvent event;
    sfVideoMode mode0 = {720, 480, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode0, "", sfClose, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
/////////////////////////////////////////////////////////////////////////////
        if (sfMouse_isButtonPressed(sfMouseLeft))
            display = true;
        if (!display) {
            cursor = sfMouse_getPositionRenderWindow(window);
            shot[1].position = (sfVector2f){(float)cursor.x, (float)cursor.y};
        } else {
            sfRenderWindow_drawPrimitives(window, shot, 2, sfLines, NULL);
            shot[0].color.a -= (shot[0].color.a ^ 5) ? 10 : 0;
            shot[1].color.a -= (shot[0].color.a == 5) ? 10 : 0;
            if (shot[1].color.a == 5) {
                new_color(&shot[0].color, &shot[1].color);
                display = false;
            }
        }
/////////////////////////////////////////////////////////////////////////////
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
