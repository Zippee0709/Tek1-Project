/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** event.c
*/

#include "tetris.h"
#include "my.h"

int move_down(game_t *game, int action, shape_t tmp)
{
    int status = 0;

    if (action == KEY_DOWN) {
        tmp.y++;
        status = my_check_shape_pos(tmp, game->x, game->y, game->map);
        if (status == 0) {
            game->current.y++;
            my_write_shape_in_map(game->current, game->tmp);
            return (1);
        }
        else if (status == 2) {
            game->current.y++;
            my_write_shape_in_map(game->current, game->map);
            game->current = my_get_new_shape(game);
            return (1);
        }
    }
    return (0);
}

int move_left(game_t *game, int action, shape_t tmp)
{
    if (action == KEY_LEFT) {
        tmp.x--;
        if (my_check_shape_pos(tmp, game->x, game->y, game->map) == 0)
            game->current.x--;
        my_write_shape_in_map(game->current, game->tmp);
        return (1);
    }
    return (0);
}

int move_right(game_t *game, int action, shape_t tmp)
{
    if (action == KEY_RIGHT) {
        tmp.x++;
        if (my_check_shape_pos(tmp, game->x, game->y, game->map) == 0)
            game->current.x++;
        my_write_shape_in_map(game->current, game->tmp);
        return (1);
    }
    return (0);
}

int move_rotate(game_t *game, int action, shape_t tmp)
{
    if (action == KEY_UP) {
        my_rotate_shape(&tmp);
        if (my_check_shape_pos(tmp, game->x, game->y, game->map) == 0)
            my_rotate_shape(&game->current);
        my_write_shape_in_map(game->current, game->tmp);
        return (1);
    }
    return (0);
}
