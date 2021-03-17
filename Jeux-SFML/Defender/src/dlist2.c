/*
** EPITECH PROJECT, 2019
** dlist.c
** File description:
** dlist 2
*/

#include "my_defender.h"

Dlist *my_push_tower_in_the_list(Dlist *list, s_game *game, sfVector2i m_pos)
{
    int status = check_click_on_all_tower(game->all_tower.pos, m_pos);
    status = check_sprite_error_tower(list, game->tmp, status, &game->error);

    switch (status) {
    case 1:
        list = push_back_dlist(list, game->AT, game->tmp);
        list->end->obj.type = 1;
        break;
    case 2:
        list = push_back_dlist(list, game->CT, game->tmp);
        list->end->obj.type = 2;
        break;
    case 3:
        list = push_back_dlist(list, game->KT, game->tmp);
        list->end->obj.type = 3;
        break;
    case 4:
        list = push_back_dlist(list, game->TT, game->tmp);
        list->end->obj.type = 4;
        break;
    }
    return (list);
}
