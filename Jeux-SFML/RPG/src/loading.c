/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** loading_screen.c
*/

#include "my_rpg.h"

static int create_texture(sfTexture **t, char const *file, sfIntRect const *rec)
{
    *t = sfTexture_createFromFile(file, rec);
    if (!(*t))
        return (-1);
    return (0);
}

static void close_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyDelete))
            sfRenderWindow_close(window);
}

int init_loading_screen(loading_t *screen)
{
    sfVector2f resize = {(RES_X + 0.) / 720, (RES_Y + 0.) / 480};
    sfVector2f position = {130 * resize.x, 100 *resize.y};

    screen->sprite = sfSprite_create();
    screen->clock = sfClock_create();
    screen->rect = (sfIntRect){0, 0, 444, 250};
    if (create_texture(&screen->texture, LOADING, NULL) < 0)
        return (-1);
    sfSprite_setTexture(screen->sprite, screen->texture, sfTrue);
    sfSprite_setTextureRect(screen->sprite, screen->rect);
    sfSprite_setPosition(screen->sprite, position);
    sfSprite_setScale(screen->sprite, resize);
    return (0);
}

void loading_screen(void *data)
{
    loading_t *screen = malloc(sizeof(*screen));

    screen->window = (sfRenderWindow *)data;
    if (init_loading_screen(screen) < 0)
        return;
    while (sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_clear(screen->window, sfBlack);
        close_event(screen->window);
        if (sfClock_getElapsedTime(screen->clock).microseconds > 60000) {
            screen->rect.left += (screen->rect.left ^ 11100) ? 444 : -11100;
            screen->rect.top += (screen->rect.left == 0) ? 250 : 0;
            sfSprite_setTextureRect(screen->sprite, screen->rect);
            sfClock_restart(screen->clock);
        }
        if (screen->rect.left == 10656 && screen->rect.top == 750)
            break;
        sfRenderWindow_drawSprite(screen->window, screen->sprite, NULL);
        sfRenderWindow_display(screen->window);
    }
    return;
}
