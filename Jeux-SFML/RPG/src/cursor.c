/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** cursor.c
*/

#include "my_rpg.h"

static void move_shape_vertex(cursor_t *curs, sfVector2f position)
{
    for (unsigned int i = 0; i ^ curs->size; i++)
        curs->get_vertex(curs->shape, i)->position = position;
}

static void move_trail_vertex(cursor_t *cu, sfVector2f position, sfVector2f z)
{
    sfVector2f scl = {4.6 * (float)RES_X / 720., 4.0 * (float)RES_Y / 480.};
    float x = ((rand() / (double)RAND_MAX) * scl.x - (scl.x / 2.));
    float y = ((rand() / (double)RAND_MAX) * scl.y - (scl.y / 2.));
    sfVector2f move = {cu->pos.x + x, cu->pos.y + y};

    cu->get_vertex(cu->trail, cu->index++)->position = move;
    cu->get_vertex(cu->trail, cu->index)->position = move;
    cu->index = (++cu->index == cu->size) ? 0 : cu->index;
    for (unsigned int i = 0; i ^ cu->size; i++)
        if (fabs(cu->get_vertex(cu->trail, i)->position.x - cu->pos.x) > z.x ||
            fabs(cu->get_vertex(cu->trail, i)->position.y - cu->pos.y) > z.y)
            cu->get_vertex(cu->trail, i)->position = position;
}

void cursor_position(sfRenderWindow *window, cursor_t *curs, sfVector2f offset)
{
    sfVector2f scl = {12.0 * (float)RES_X / 720., 8.0 * (float)RES_Y / 480.};
    sfVector2f li = {50. * (float)RES_X / 720., 50. * (float)RES_Y / 480.};
    float x = ((rand() / (double)RAND_MAX) * scl.x - (scl.x / 2.));
    float y = ((rand() / (double)RAND_MAX) * scl.y - (scl.y / 2.));

    curs->pos.x = (float)curs->mouse_pos(window).x + offset.x;
    curs->pos.y = (float)curs->mouse_pos(window).y + offset.y;
    move_shape_vertex(curs, (sfVector2f){curs->pos.x + x, curs->pos.y + y});
    move_trail_vertex(curs, (sfVector2f){curs->pos.x + x, curs->pos.y + y}, li);
    sfSprite_setPosition(curs->pointer, curs->pos);
}

static int init_pointer(cursor_t *cursor)
{
    sfVector2f scale = {720., 480.};
    sfVector2f origin = {2.6 * (float)RES_X / 720., 2.6 * (float)RES_Y / 480.};

    cursor->pointer = create_sprite(&cursor->texture, CURSOR, scale);
    if (!cursor->pointer)
        return (-1);
    sfSprite_setOrigin(cursor->pointer, origin);
    sfSprite_setPosition(cursor->pointer, cursor->pos);
    return (0);
}

cursor_t init_cursor(sfRenderWindow *window)
{
    cursor_t cursor;
    sfVertex element;

    cursor.trail = NULL;
    cursor.mouse_pos = sfMouse_getPositionRenderWindow;
    cursor.get_vertex = sfVertexArray_getVertex;
    cursor.index = 0;
    cursor.size = 30;
    if (init_pointer(&cursor) < 0)
        return (cursor);
    cursor.trail = sfVertexArray_create();
    cursor.shape = sfVertexArray_create();
    for (unsigned int i = 0; i != cursor.size; i++) {
        element.position.x = cursor.mouse_pos(window).x * 1.;
        element.position.y = cursor.mouse_pos(window).y * 1.;
        element.color = (sfColor){255 - i * 6, 255 - i * 2, 255, 255};
        sfVertexArray_append(cursor.trail, element);
    }
    cursor.shape = sfVertexArray_copy(cursor.trail);
    return (cursor);
}
