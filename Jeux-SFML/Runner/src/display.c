/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** all usefull function for draw and display
*/

#include "runner.h"

void set_monster_sprite_pos(s_game *game)
{    
    sfVector2f pos = sfSprite_getPosition(game->monster.sprite);

    if (pos.x < -50) {
        game->nb_zombie = game->nb_zombie - 1;
        game->move_speed.x = game->move_speed.x - 0.2;
        sfSprite_setPosition(game->monster.sprite, game->monster.pos);
    }
    pos = sfSprite_getPosition(game->monster1.sprite);
    if (pos.x < -50) {
        game->nb_zombie = game->nb_zombie - 1;
        game->move_speed.x = game->move_speed.x - 0.2;
        sfSprite_setPosition(game->monster1.sprite, game->monster1.pos);
    }
    pos = sfSprite_getPosition(game->monster2.sprite);
    if (pos.x < -50) {
        game->nb_zombie = game->nb_zombie - 1;
        game->move_speed.x = game->move_speed.x - 0.2;
        sfSprite_setPosition(game->monster2.sprite, game->monster2.pos);
    }
}

void move_monster_sprite(s_game *game)
{
    if (game->m1 == 1) 
        sfSprite_move(game->monster.sprite, game->move_speed);
    if (game->m2 == 1)
        sfSprite_move(game->monster1.sprite, game->move_speed);
    if (game->m3 == 1)
        sfSprite_move(game->monster2.sprite, game->move_speed);
    set_monster_sprite_pos(game);
}

void draw_all_sprite(sfRenderWindow *window, s_game *game)
{
    sfRenderWindow_drawSprite(window, game->sky_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->rock_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->cloud_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->tree_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->sprite.sprite, NULL);
}

void draw_all_monster(sfRenderWindow *window, s_game *game)
{
    if (game->m1 == 1)
        sfRenderWindow_drawSprite(window, game->monster.sprite, NULL);
    if (game->m2 == 1)
        sfRenderWindow_drawSprite(window, game->monster1.sprite, NULL);
    if (game->m3 == 1)
        sfRenderWindow_drawSprite(window, game->monster2.sprite, NULL);
}
