/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** useful.c
*/

#include "my_rpg.h"

sfRenderWindow *create_window(bool fullscreen, char const *name)
{
    sfRenderWindow *wndow = NULL;
    sfVideoMode mode = {RES_X, RES_Y, 32};

    if (fullscreen == true) {
        mode = sfVideoMode_getDesktopMode();
        wndow = sfRenderWindow_create(mode, name, sfClose | sfFullscreen, NULL);
    } else
        wndow = sfRenderWindow_create(mode, name, sfClose | sfResize, NULL);
    if (!wndow)
        return (NULL);
    sfRenderWindow_setFramerateLimit(wndow, 60);
    sfRenderWindow_setMouseCursorVisible(wndow, sfFalse);
    sfRenderWindow_setVerticalSyncEnabled(wndow, sfTrue);
    return (wndow);
}

sfSprite *create_sprite(sfTexture **texture, char const *str, sfVector2f scale)
{
    sfSprite *sprite = NULL;
    sfVector2f resize = {(RES_X + 0.) / scale.x, (RES_Y + 0.) / scale.y};

    *texture = sfTexture_createFromFile(str, NULL);
    if (!(*texture))
        return (NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, *texture, sfTrue);
    sfSprite_setScale(sprite, resize);
    return (sprite);
}

sfVector2f create_vector(float x, float y, sfVector2f scale)
{
    sfVector2f vector;

    vector.x = x * (RES_X + 0.) / scale.x;
    vector.y = y * (RES_Y + 0.) / scale.y;
    return (vector);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void move_rect(sfIntRect *rect, int offset, int max)
{
    rect->left += offset;
    if (rect->left == max)
        rect->left = 0;
}
