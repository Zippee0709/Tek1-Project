/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_menu.c
*/

#include "my_rpg.h"

static int create_menu_logo(sprite_t *logo, sprite_t *border)
{
    sfVector2f scale = {1920.0, 1080.0};
    sfVector2f size = {4 * (float)RES_X / 1920., 4 * (float)RES_Y / 1080.};
    sfVector2f grow = {5.72 * (float)RES_X / 1920., 4.8 * (float)RES_Y / 1080.};

    init_fctptr(logo);
    logo->sprite = logo->create_sprite(&logo->texture, MENUS, scale);
    border->sprite = logo->create_sprite(&border->texture, CADRE, scale);
    if (!logo->sprite || !border->sprite)
        return (FAILURE);
    logo->rect = logo->create_rect(419, 686, 325, 60);
    logo->vector = logo->create_vector(360, 240, scale);
    sfSprite_setTextureRect(logo->sprite, logo->rect);
    sfSprite_setPosition(logo->sprite, logo->vector);
    sfSprite_setScale(logo->sprite, size);
    sfSprite_setScale(border->sprite, grow);
    return (SUCCESS);
}

static int create_menu_button(button_t *button, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {2. * (float)RES_X / 720., 2. * (float)RES_Y / 480.};

    button->sprite = create_sprite(&button->texture, BUTTONS, scale);
    if (!button->sprite)
        return (FAILURE);
    button->rect = create_rect(top, 0, 80, 20);
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->vector = create_vector(x, y, scale);
    sfSprite_setPosition(button->sprite, button->vector);
    sfSprite_setScale(button->sprite, size);
    return (SUCCESS);
}

static int create_background_menu(sprite_t *background, char const *name)
{
    sfVector2f scale = {1920., 1080.};
    sfVector2f size = {3. * (float)RES_X / 720., 3. * (float)RES_Y / 480.};

    background->sprite = create_sprite(&background->texture, name, scale);
    if (!background->sprite)
        return (FAILURE);
    background->rect = create_rect(0, 0, 544, 160);
    background->clock = sfClock_create();
    sfSprite_setTextureRect(background->sprite, background->rect);
    sfSprite_setScale(background->sprite, size);
    sfSprite_setPosition(background->sprite, (sfVector2f){0.0, 0.0});
    return (SUCCESS);
}

void init_menu_fct(void (*ptr[4])(rpg_t *rpg))
{
    ptr[0] = play_game;
    ptr[1] = load_game;
    ptr[2] = help_game;
    ptr[3] = exit_game;
}

int load_menu(menu_t *menu)
{
    menu->button = malloc(sizeof(button_t) * 4);
    menu->bg = malloc(sizeof(sprite_t) * 5);
    if (create_menu_logo(&menu->logo[0], &menu->logo[1]) == FAILURE ||
        menu->button == NULL || menu->bg == NULL)
        return (FAILURE);
    init_menu_fct(menu->ptr_fct);
    if ((create_menu_button(&menu->button[0], 20, 750, 500) |
        create_menu_button(&menu->button[1], 41, 750, 625) |
        create_menu_button(&menu->button[2], 62, 750, 750) |
        create_menu_button(&menu->button[3], 0, 750, 875) |
        create_background_menu(&menu->bg[0], MENU_BG) |
        create_background_menu(&menu->bg[1], BACK_MOUNT) |
        create_background_menu(&menu->bg[2], FRONT_MOUNT) |
        create_background_menu(&menu->bg[3], BACK_TREE) |
        create_background_menu(&menu->bg[4], FRONT_TREE)) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
