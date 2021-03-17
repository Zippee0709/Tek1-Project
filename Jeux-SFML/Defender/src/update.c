/*
** EPITECH PROJECT, 2019
** update.c
** File description:
** update.c
*/

#include "my_defender.h"

void my_push_enemies_clock(s_game *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock_monster);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 2) {
        game->enemies = push_back_dlist(game->enemies, game->monster,
                                        game->monster.pos);
        sfClock_restart(game->clock_monster);
    }
}

void my_push_tower_attack(s_game *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock_shots);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 1) {
        check_tower_type(game);
        sfClock_restart(game->clock_shots);
    }
}

void my_sprite_update(s_game *game)
{
    if (game->enemies != NULL &&
       check_shots_on_enemies(game) == 1) {
        game->shots = pop_begin_dlist(game->shots);
    }
    if (game->enemies != NULL && check_life_on_enemies(game->enemies) == 1) {
        game->enemies = pop_begin_dlist(game->enemies); 
        game->shots = pop_begin_dlist(game->shots);
    }
    if (game->enemies != NULL)
        move_sprite_dlist(game->enemies, game->gr);
    if (game->shots != NULL)
        move_shots_dlist(game->shots, game->enemies);
    my_push_enemies_clock(game);
    my_push_tower_attack(game);
    return;
}

void my_update_game(s_game *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock_monster);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 2) {
        game->enemies = push_back_dlist(game->enemies, game->monster,
                                       game->monster.pos);
        sfClock_restart(game->clock_monster);
    }
    my_update_game_value(game);
    my_sprite_update(game);
    if (game->castle_life <= 0)
        game->status = FINAL;
}
