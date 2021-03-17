/*
** EPITECH PROJECT, 2019
** check_tower.c
** File description:
** check_tower.c
*/

#include "my_defender.h"

int check_sprite_error_tower(Dlist *list, sfVector2f pos, int status, int *error)
{
    Dlist_node *tmp;
    sfVector2f max;
    sfVector2i m_pos = {(float)pos.x, (float)pos.y};

    if (list == NULL)
        return (status);
    tmp = list->begin;
    while (tmp != NULL) {
        max.x = tmp->obj.pos.x + 80;
        max.y = tmp->obj.pos.y + 60;
        if (check_pos_value(m_pos, tmp->obj.pos, max) == 1) {
            *error = ERROR_TOWER;
            return (0);
        }
        tmp = tmp->next;
    }
    return (status);
}

int check_click_on_all_tower(sfVector2f s_pos, sfVector2i m_pos)
{
    int i = 1;
    sfVector2f max = s_pos;
    max.x = max.x + 256;
    max.y = max.y + 256;

    while (i <= 4) {
        if (check_pos_value(m_pos, s_pos, max) == 1)
            return (i);
        else if (max.x == s_pos.x + 512) {
            max.y = max.y + 256;
            max.x = s_pos.x;
        }
        max.x = max.x + 256;
        i++;
    }
    return (0);
}

int check_click_on_all_skill(sfVector2f s_pos, sfVector2i m_pos)
{
    int i = 5;
    sfVector2f max = s_pos;
    max.x = max.x + 125;
    max.y = max.y + 125;

    while (i <= 8) {
        if (check_pos_value(m_pos, s_pos, max) == 1)
            return (i);
        else if (max.x == s_pos.x + 250) {
            max.y = max.y + 125;
            max.x = s_pos.x;
        }
        max.x = max.x + 125;
        i++;
    }
    return (0);
}
