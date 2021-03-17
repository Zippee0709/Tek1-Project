/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** all usefull function for free
*/

#include "my_defender.h"

void my_free_ground_sprite(s_ground *ground)
{
    sfSprite_destroy(ground->UL.sprite);
    sfSprite_destroy(ground->UR.sprite);
    sfSprite_destroy(ground->DL.sprite);
    sfSprite_destroy(ground->DR.sprite);
    sfSprite_destroy(ground->BG.sprite);
    sfSprite_destroy(ground->HG.sprite);
    sfSprite_destroy(ground->VG.sprite);
    sfSprite_destroy(ground->GG.sprite);
}

void my_free_ground_texture(s_ground *ground)
{
    sfTexture_destroy(ground->UL.texture);
    sfTexture_destroy(ground->UR.texture);
    sfTexture_destroy(ground->DL.texture);
    sfTexture_destroy(ground->DR.texture);
    sfTexture_destroy(ground->BG.texture);
    sfTexture_destroy(ground->HG.texture);
    sfTexture_destroy(ground->VG.texture);
    sfTexture_destroy(ground->GG.texture);
}

void my_free_sprite(s_game *game)
{
    sfSprite_destroy(game->menu.sprite);
    sfSprite_destroy(game->backgr.sprite);
    sfSprite_destroy(game->castle.sprite);
    sfSprite_destroy(game->monster.sprite);
}

void my_free_texture(s_game *game)
{
    sfTexture_destroy(game->menu.texture);
    sfTexture_destroy(game->backgr.texture);
    sfTexture_destroy(game->castle.texture);
    sfTexture_destroy(game->monster.texture);
    sfTexture_destroy(game->play.texture);
    sfTexture_destroy(game->exit.texture);
}

void my_free_all(s_game *game)
{
    my_free_sprite(game);
    my_free_texture(game);
    my_free_ground_sprite(&game->ground);
    my_free_ground_texture(&game->ground);
    my_free_double_tab(game->map);
    my_free_clock(game);
    my_free_dlist(game->gr);
    my_free_dlist(game->base_gr);
    my_free_dlist(game->enemies);
    my_free_dlist(game->tower_map);
    my_free_dlist(game->shots);
    my_free_music(game);
    sfRenderWindow_destroy(game->window);
}
