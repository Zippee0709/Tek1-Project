/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** useful2.c
*/

#include "my_rpg.h"

sfText *create_text(char *str, char const *new_font,
                    sfColor color, sfVector2f vector)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(new_font);

    if (!font || !text || !str)
        return (NULL);
    vector.x = vector.x * RES_X / 1920;
    vector.y = vector.y * RES_Y / 1080;
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setScale(text, vector);
    return (text);
}

sfVector2f return_size(sfTexture *texture)
{
    sfVector2f size;

    size.x = (sfTexture_getSize(texture)).x + 0.;
    size.y = (sfTexture_getSize(texture)).y + 0.;
    size.x = size.x * RES_X / 1920;
    size.y = size.y * RES_Y / 1080;
    return (size);
}

void init_fctptr(sprite_t *obj)
{
    obj->create_sprite = create_sprite;
    obj->create_rect = create_rect;
    obj->create_vector = create_vector;
}
