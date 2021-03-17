/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** objects.c
*/

#include "my_rpg.h"

static void create_object(object_t *obj, const char *filepath, sfVector2f pos)
{
    sfVector2f scale = {1920., 1080.};

    obj->spr = create_sprite(&obj->tex, filepath, scale);
    obj->pos = create_vector(pos.x, pos.y, scale);
    sfSprite_setPosition(obj->spr, obj->pos);
}

object_t *load_objects(object_t *obj, int sz, char const **pth, sfVector2f *pos)
{
    obj = malloc(sizeof(object_t) * sz);
    if (!obj)
        return (NULL);
    for (int i = 0; i != sz; i++)
        create_object(&obj[i], pth[i], pos[i]);
    return (obj);
}
