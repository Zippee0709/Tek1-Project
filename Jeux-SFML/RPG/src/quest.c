/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** quest.c
*/

#include "my_rpg.h"

int create_quest_button(button_t *quest, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {1. * (float)RES_X / 720., 1. * (float)RES_Y / 480.};

    quest->sprite = create_sprite(&quest->texture, QUEST_BUTTON, scale);
    if (!quest->sprite)
        return (FAILURE);
    quest->rect = create_rect(top, 0, 50, 50);
    sfSprite_setTextureRect(quest->sprite, quest->rect);
    quest->vector = create_vector(x, y, scale);
    sfSprite_setPosition(quest->sprite, quest->vector);
    sfSprite_setScale(quest->sprite, size);
    return (SUCCESS);
}

int create_quest_infos(button_t *quest, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {2. * (float)RES_X / 720., 2. * (float)RES_Y / 480.};

    quest->sprite = create_sprite(&quest->texture, QUEST_INFOS, scale);
    if (!quest->sprite)
        return (FAILURE);
    quest->rect = create_rect(top, 0, 115, 80);
    sfSprite_setTextureRect(quest->sprite, quest->rect);
    quest->vector = create_vector(x, y, scale);
    sfSprite_setPosition(quest->sprite, quest->vector);
    sfSprite_setScale(quest->sprite, size);
    return (SUCCESS);
}

int load_quest(rpg_t *rpg)
{
    rpg->quest_button = false;
    rpg->quest_infos = false;
    rpg->quest = malloc(sizeof(button_t) * 2);
    if ((create_quest_button(&rpg->quest[0], 0, 0, 0) |
        create_quest_infos(&rpg->quest[1], 0, RES_X / 2, RES_Y / 2))
        == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
