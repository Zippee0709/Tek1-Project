/*
** EPITECH PROJECT, 2019
** collision.c
** File description:
** collision.c
*/

#include "my_defender.h"

void my_update_game_value(s_game *game)
{
    Dlist_node *tmp;

    if (game->enemies == NULL)
        return;
    tmp = game->enemies->begin;
    while (tmp != NULL) {
        if (tmp->obj.pos.x >= game->castle.pos.x &&
           tmp->obj.pos.y >= game->castle.pos.y)
            game->castle_life -= tmp->obj.stat.power;
        tmp = tmp->next;
    }
}
