/*
** EPITECH PROJECT, 2019
** pnj
** File description:
** rpg
*/

#include "my_rpg.h"

int create_pnj(sprite_t *pnj, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {2. * (float)RES_X / 1366., 2. * (float)RES_Y / 768.};

    pnj->sprite = create_sprite(&pnj->texture, "ressources/pnj.png", scale);
    if (!pnj->sprite)
        return (FAILURE);
    pnj->rect = create_rect(top, 0, 30, 47);
    sfSprite_setTextureRect(pnj->sprite, pnj->rect);
    pnj->vector = create_vector(x, y, scale);
    sfSprite_setPosition(pnj->sprite, pnj->vector);
    sfSprite_setScale(pnj->sprite, size);
    return (SUCCESS);
}

int create_dial(rpg_t *rpg, int top, int x, int y)
{
    sfVector2f scale = {1920, 1080};
    sfVector2f size = {2. * (float)RES_X / 1366., 2. * (float)RES_Y / 768.};

    rpg->dial.sprite = create_sprite(&rpg->dial.texture, HODOR, scale);
    if (!rpg->dial.sprite)
        return (FAILURE);
    rpg->dial.rect = create_rect(top, 0, 106, 61);
    sfSprite_setTextureRect(rpg->dial.sprite, rpg->dial.rect);
    rpg->dial.vector = create_vector(x, y, scale);
    sfSprite_setPosition(rpg->dial.sprite, rpg->dial.vector);
    sfSprite_setScale(rpg->dial.sprite, size);
    return (SUCCESS);
}

void pnj_event(rpg_t *rpg, sprite_t *pnj)
{
    sfFloatRect mob = sfSprite_getGlobalBounds(pnj->sprite);
    sfFloatRect man = sfSprite_getGlobalBounds(rpg->player.sprite);
    static int a = 0;

    if (a > 0) {
        rpg->dial.texture = sfTexture_createFromFile("ressources/mi.png", NULL);
        rpg->dial.vector = (sfVector2f){710., 585.};
        sfSprite_setTexture(rpg->dial.sprite, rpg->dial.texture, sfTrue);
    } if (sfFloatRect_intersects(&mob, &man, NULL) == sfTrue
        && pnj->vector.y < 680) {
        pnj->vector = (sfVector2f){pnj->vector.x, pnj->vector.y + 10};
        sfSprite_setPosition(pnj->sprite, pnj->vector);
        a++;
        TALK++;
    } if (pnj->vector.y >= 680) { rpg->quest_button = true; TALK = -10;
    } if (sfFloatRect_intersects(&mob, &man, NULL) == sfFalse
        && TALK && pnj->vector.y >= 680) {
        rpg->dial.vector = (sfVector2f){-10000., -10000.};
        TALK = -10;
    }
}
