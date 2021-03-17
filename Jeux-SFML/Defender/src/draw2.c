/*
** EPITECH PROJECT, 2019
** draw2.c
** File description:
** draw2.c
*/

#include "my_defender.h"

Dlist *check_witch_shots(Dlist *list, sfVector2f tower, int status,
                        s_game *game)
{
    tower.x += 25;
    tower.y += 15;
    switch (status) {
    case 1:
        list = push_back_dlist(list, game->shots_s.arrow, tower);
        break;
    case 2:
        list = push_back_dlist(list, game->shots_s.fire, tower);
        break;
    case 3:
        list = push_back_dlist(list, game->shots_s.rock, tower);
        break;
    case 4:
        list = push_back_dlist(list, game->shots_s.ninja, tower);
        break;
    }
    return (list);
}

void check_tower_type(s_game *game)
{
    Dlist_node *tmp;

    if (game->tower_map == NULL)
        return;
    tmp = game->tower_map->begin;
    while (tmp != NULL) {
        game->shots = check_witch_shots(game->shots, tmp->obj.pos,
                                            tmp->obj.type, game);
        tmp = tmp->next;
    }
}

void draw_castle_life(s_game *game)
{
    char *str_score = my_int_convert_str(game->castle_life);

    sfRenderWindow_drawText(game->window, game->text.castle, NULL);
    sfText_setString(game->text.castle_life, str_score);
    sfRenderWindow_drawText(game->window, game->text.castle_life, NULL);
    free(str_score);
}

void draw_score(s_game *game)
{
    char *str_score = my_int_convert_str(game->score);
    sfTime time = sfClock_getElapsedTime(game->clock_score);
    float seconds = time.microseconds / 1000000.0;

    sfRenderWindow_drawText(game->window, game->text.text_score, NULL);
    sfText_setString(game->text.score, str_score);
    sfRenderWindow_drawText(game->window, game->text.score, NULL);
    if (seconds > 0.2 && game->status == GAME) {
        game->score++;
        sfClock_restart(game->clock_score);
    }
    free(str_score);
}
