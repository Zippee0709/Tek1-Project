/*
** EPITECH PROJECT, 2019
** update_tower.c
** File description:
** update tower
*/

#include "my_defender.h"

s_stat update_tower_stat(int status, s_stat stat)
{
    switch (status) {
    case 5:
        stat.power += 1;
        break;
    case 6:
        stat.armor += 1;
        break;
    case 7:
        stat.speed += 1;
        break;
    case 8:
        stat.life += 1;
        break;
    }
    return (stat);
}

void update_tower_value(s_game *game, Dlist *list)
{
    Dlist_node *tmp;
    sfVector2f max;

    if (list == NULL)
        return;
    tmp = list->begin;
    while (tmp != NULL) {
        max.x = tmp->obj.pos.x + 80;
        max.y = tmp->obj.pos.y + 60;
        if (check_fpos_value(game->tmp, tmp->obj.pos, max) == 1) {
            tmp->obj.stat = update_tower_stat(game->tower_status,
                                             tmp->obj.stat);
        }
        tmp = tmp->next;
    }
}

void check_tower_status(s_game *game, sfVector2i p)
{
    sfVector2f max;
    max.x = game->all_tower.pos.x + 512;
    max.y = game->all_tower.pos.y + 512;

    if (game->tower_status == 1 &&
       check_pos_value(p, game->all_tower.pos, max) == 1) {
        game->tower_map = my_push_tower_in_the_list(game->tower_map, game, p);
        game->m_pos = p;
        game->tower_status = 0;
    }
    max.x = game->skill.pos.x + 600;
    max.y = game->skill.pos.y + 300;
    if (game->tower_status == 2 && check_pos_value(p, game->skill.pos, max)) {
        game->tower_status = check_click_on_all_skill(game->skill.pos, p);
        update_tower_value(game, game->tower_map);
        game->tower_status = 0;
    }
}

void update_tower_status(s_game *game, sfVector2i m_pos)
{
    if (game->status == 3) {
        game->tower_map = my_push_tower_in_the_list(game->tower_map,
                                                   game, m_pos);
        game->status = 0;
    }
}

