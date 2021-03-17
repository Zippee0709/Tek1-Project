/*
** EPITECH PROJECT, 2019
** check_map.c
** File description:
** check_map.c
*/

#include "my_defender.h"

Dlist *my_check_direction(int status, sfVector2f pos, Dlist *list, s_game *game)
{
    switch (status) {
    case 1:
        list = push_back_dlist(list, game->ground.DR, pos);
        break;
    case 2:
        list = push_back_dlist(list, game->ground.DL, pos);
        break;
    case 3:
        list = push_back_dlist(list, game->ground.UR, pos);
        break;
    case 4:
        list = push_back_dlist(list, game->ground.UL, pos);
        break;
    }
    return (list);
}

int my_check_map_status(char **map, int x, int y)
{
    if (x == 0 || y == 0)
        return (0);
    if (map[y - 1][x] == 'G' && map[y][x + 1] == 'G')
        return (1);
    if ((map[y - 1][x] == 'G'  || map[y - 1][x] == 'H') &&
            map[y][x - 1] == 'G')
        return (2);
    if (map[y + 1][x] == 'G' && map[y][x + 1] == 'G')
        return (3);
    if (map[y + 1][x] == 'G' && map[y][x - 1] == 'G')
        return (4);
    return (0);
}

Dlist *my_check_witch_ground(Dlist *list, s_game *game,
                            sfVector2f pos, char **map)
{
    sfVector2i i = game->i;
    int status = my_check_map_status(game->map, i.x, i.y);

    if (game->i.x != 0 && game->i.y != 0 && status > 0)
        list = my_check_direction(status, pos, list, game);
    else if (map[i.y + 1][i.x] == 'G')
        list = push_back_dlist(list, game->ground.VG, pos);
    else if (map[i.y][i.x + 1] == 'G')
        list = push_back_dlist(list, game->ground.HG, pos);
    return (list);
}

Dlist *my_check_map_info(char letter, s_game *game, sfVector2f pos, Dlist *list)
{
    if (letter == '0')
        list = push_back_dlist(list, game->ground.BG, pos);
    else if (letter == 'G')
        list = my_check_witch_ground(list, game, pos, game->map);
    return (list);
}
