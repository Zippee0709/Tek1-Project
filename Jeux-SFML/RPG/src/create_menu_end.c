/*
** EPITECH PROJECT, 2019
** create_menu_end.c
** File description:
** create_menu_end.c
*/

#include "my_rpg.h"

static int create_game_end_logo(sprite_t *logo)
{
    sfVector2f scale = {1920.0, 1080.0};
    sfVector2f size = {4 * (float)RES_X / 1920., 3.5 * (float)RES_Y / 1080.};

    init_fctptr(logo);
    logo->sprite = logo->create_sprite(&logo->texture, MENU_END, scale);
    if (!logo->sprite)
        return (FAILURE);
    logo->rect = logo->create_rect(0, 0, 320, 210);
    logo->vector = logo->create_vector(360, 240, scale);
    sfSprite_setTextureRect(logo->sprite, logo->rect);
    sfSprite_setPosition(logo->sprite, logo->vector);
    sfSprite_setScale(logo->sprite, size);
    return (SUCCESS);
}

static int create_game_end_button(button_t *button, int x, int y, char *str)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {2. * (float)RES_X / 720., 2. * (float)RES_Y / 480.};
    sfVector2f text = {1. * (float)RES_X / 720., 1. * (float)RES_Y / 480.};
    float pos = 125. * (float)RES_X / 1920.;

    button->sprite = create_sprite(&button->texture, MENUS, scale);
    if (!button->sprite)
        return (FAILURE);
    button->rect = create_rect(71, 803, 72, 20);
    button->vector = create_vector2f(x, y, scale);
    button->text_vector = create_vector2f(x + pos, y + 15, scale);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->vector);
    button->text = create_text(str, FONT, sfYellow, text);
    sfText_setPosition(button->text, button->text_vector);
    sfSprite_setScale(button->sprite, size);
    return (SUCCESS);
}

int load_game_end(menu_t *menu)
{
    create_game_end_logo(&menu->logo);
    menu->button = malloc(sizeof(button_t) * 3);
    menu->bg = NULL;

    if (menu->button == NULL)
        return (FAILURE);
    create_game_end_button(&menu->button[0], 400, 830, "CONTINUE");
    create_game_end_button(&menu->button[1], 800, 830, "  AGAIN");
    create_game_end_button(&menu->button[2], 1200, 830, "  QUIT");
    return (SUCCESS);
}
