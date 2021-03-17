/*
** EPITECH PROJECT, 2018
** window.h
** File description:
** stuct for c graphic project
*/

typedef struct framebuffer_t
{
    sfUint8 *pixel;
    sfVector2f size;
    sfVector2f square;
    int bits;
    sfRectangleShape *rect;
    sfRenderWindow *window;    
}framebuffer_t;
