/*
** EPITECH PROJECT, 2019
** check_func.c
** File description:
** check_func.c
*/

#include "my_defender.h"

int check_pos_value(sfVector2i mouse, sfVector2f s_pos, sfVector2f max)
{
    sfVector2f m_pos;
    m_pos.x = (float)mouse.x;
    m_pos.y = (float)mouse.y;

    if (m_pos.x >= s_pos.x && m_pos.y >= s_pos.y &&
        m_pos.x <= max.x && m_pos.y <= max.y)
        return (1);
    return (0);
}

int check_fpos_value(sfVector2f mouse, sfVector2f s_pos, sfVector2f max)
{
    sfVector2f m_pos;
    m_pos.x = mouse.x;
    m_pos.y = mouse.y;

    if (m_pos.x >= s_pos.x && m_pos.y >= s_pos.y &&
        m_pos.x <= max.x && m_pos.y <= max.y)
        return (1);
    return (0);
}

int check_click_on_list(s_game *game, Dlist *list, sfVector2i m_pos)
{
    Dlist_node *tmp = list->begin;
    sfVector2f max = tmp->obj.pos;

    while (tmp != NULL) {
        max.x = tmp->obj.pos.x + 80;
        max.y = tmp->obj.pos.y + 60;
        if (check_pos_value(m_pos, tmp->obj.pos, max) == 1) {
            game->tmp = tmp->obj.pos;
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int check_click_on_tower(s_game *game, Dlist *list, sfVector2i m_pos)
{
    Dlist_node *tmp;
    sfVector2f max;

    if (list == NULL)
        return (game->tower_status);
    tmp = list->begin;
    max = tmp->obj.pos;
    while (tmp != NULL) {
        max.x = tmp->obj.pos.x + 80;
        max.y = tmp->obj.pos.y + 60;
        if (check_pos_value(m_pos, tmp->obj.pos, max) == 1) {
            game->tmp = tmp->obj.pos;
            game->tower_status += 1;
            return (game->tower_status);
        }
        tmp = tmp->next;
    }
    return (game->tower_status);
}

