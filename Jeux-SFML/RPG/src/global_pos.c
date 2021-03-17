/*
** EPITECH PROJECT, 2019
** global_pos.c
** File description:
** global_pos.c
*/

#include "my_rpg.h"

void check_enemies_value(rpg_t *rpg)
{
    sfVector2f pos = {-500, 400};
    
    if (rpg->enemies.stat.hp <= 0) {
        rpg->player.stat.level++;
        rpg->player.stat.hp += 50;
        rpg->player.stat.attack += 10;
        rpg->player.stat.defense += 10;
        rpg->enemies.stat.hp = rpg->player.stat.hp;
        sfSprite_setPosition(rpg->enemies.sprite, pos);
        sfRenderWindow_drawSprite(rpg->screen.window, rpg->enemies.sprite, NULL);
    }
}

void player_global_intersect(rpg_t *rpg)
{
    sfFloatRect p_rect = sfSprite_getGlobalBounds(rpg->player.sprite);
    sfFloatRect m_rect = sfSprite_getGlobalBounds(rpg->enemies.sprite);
    sfFloatRect s_rect = sfSprite_getGlobalBounds(rpg->cursor.pointer);
    
    if (sfFloatRect_intersects(&p_rect, &m_rect, NULL) == sfTrue)
        rpg->player.stat.hp--;
    else if (sfFloatRect_intersects(&s_rect, &m_rect, NULL) == sfTrue &&
             sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        rpg->enemies.stat.hp--;
    check_enemies_value(rpg);
}
