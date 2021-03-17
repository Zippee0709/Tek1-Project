/*
** EPITECH PROJECT, 2019
** basic_func.c
** File description:
** basic_func.c
*/

#include "my_defender.h"

Dlist *my_fill_dlist_ground(s_game *game, char **map, char letter, Dlist *list)
{
    sfVector2f pos = {0, 0};
    game->i.x = 0;
    game->i.y = 0;

    while (map[game->i.y] != NULL) {
        while (map[game->i.y][game->i.x] != '\0') {
            if (map[game->i.y][game->i.x] == letter)
                list = my_check_map_info(letter, game, pos, list);
            game->i.x++;
            pos.x = pos.x + 80;
        }
        pos.y = pos.y + 60;
        pos.x = 0;
        game->i.x = 0;
        game->i.y++;
    }
    return (list);
}
