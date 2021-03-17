/*
** EPITECH PROJECT, 2019
** set.c
** File description:
** set.c
*/

#include "my_defender.h"

void my_set_texture(s_game *game)
{
    sfSprite_setTexture(game->menu.sprite, game->menu.texture, sfTrue);
    sfSprite_setTexture(game->backgr.sprite, game->backgr.texture, sfTrue);
    sfSprite_setTexture(game->monster.sprite, game->monster.texture, sfTrue);
    sfSprite_setTexture(game->castle.sprite, game->castle.texture, sfTrue);
    sfSprite_setTexture(game->all_tower.sprite, game->all_tower.texture,
                       sfTrue);
    sfSprite_setTexture(game->skill.sprite, game->skill.texture, sfTrue);
    sfSprite_setTexture(game->pause.sprite, game->pause.texture, sfTrue);
    sfSprite_setTexture(game->final.sprite, game->final.texture, sfTrue);
    sfSprite_setTexture(game->AT.sprite, game->AT.texture, sfTrue);
    sfSprite_setTexture(game->CT.sprite, game->CT.texture, sfTrue);
    sfSprite_setTexture(game->KT.sprite, game->KT.texture, sfTrue);
    sfSprite_setTexture(game->TT.sprite, game->TT.texture, sfTrue);
    sfSprite_setTextureRect(game->monster.sprite, game->monster.rect);
}

void my_set_position(s_game *game)
{
    sfSprite_setPosition(game->all_tower.sprite, game->all_tower.pos);
    sfSprite_setPosition(game->skill.sprite, game->skill.pos);
}
