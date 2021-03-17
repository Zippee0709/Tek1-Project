/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** open a window with SFML
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>
#include "include/window.h"

void my_check_event(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event) == sfTrue)
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer = malloc(sizeof(*buffer));

    buffer->rect = sfRectangleShape_create();
    buffer->bits = 32;
    buffer->size.x = 10;
    buffer->size.y = 10;
    buffer->pixel = malloc(width * height * buffer->bits / 8);
    return (buffer);
}

void put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
    sfVector2f size = {x, y};

    sfRectangleShape_setSize(buffer->rect, buffer->size);
    sfRectangleShape_setFillColor(buffer->rect, color);
    sfRectangleShape_setPosition(buffer->rect, size);
    sfRenderWindow_drawRectangleShape(buffer->window, buffer->rect, NULL);
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    framebuffer_t *buffer = framebuffer_create(800, 600);
    sfColor color = {255, 0, 0, 125};
    sfEvent event;

    buffer->window = sfRenderWindow_create(mode, "window", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(buffer->window) == sfTrue) {
        my_check_event(buffer->window, &event);
        put_pixel(buffer, 10, 10, color);
        put_pixel(buffer, 100, 100, color);
        put_pixel(buffer, 250, 400, color);
        sfRenderWindow_display(buffer->window);
    }
    sfRenderWindow_destroy(buffer->window);
    free(buffer);
    return (0);
}
