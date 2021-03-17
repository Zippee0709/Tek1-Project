/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create.c
*/

#include "my_defender.h"

void my_create_ground_sprite(s_ground *ground)
{
    ground->UL.sprite = sfSprite_create();
    ground->UR.sprite = sfSprite_create();
    ground->DL.sprite = sfSprite_create();
    ground->DR.sprite = sfSprite_create();
    ground->BG.sprite = sfSprite_create();
    ground->HG.sprite = sfSprite_create();
    ground->VG.sprite = sfSprite_create();
    ground->GG.sprite = sfSprite_create();
}

void my_create_ground_texture(s_ground *ground)
{
    ground->UL.texture = sfTexture_createFromFile("img/gr/UL.png", NULL);
    ground->UR.texture = sfTexture_createFromFile("img/gr/UR.png", NULL);
    ground->DL.texture = sfTexture_createFromFile("img/gr/DL.png", NULL);
    ground->DR.texture = sfTexture_createFromFile("img/gr/DR.png", NULL);
    ground->BG.texture = sfTexture_createFromFile("img/gr/BG.png", NULL);
    ground->HG.texture = sfTexture_createFromFile("img/gr/HG.png", NULL);
    ground->VG.texture = sfTexture_createFromFile("img/gr/VG.png", NULL);
    ground->GG.texture = sfTexture_createFromFile("img/gr/GG.png", NULL);
}

void my_create_sprite(s_game *game)
{
    game->menu.sprite = sfSprite_create();
    game->backgr.sprite = sfSprite_create();
    game->monster.sprite = sfSprite_create();
    game->castle.sprite = sfSprite_create();
    game->all_tower.sprite = sfSprite_create();
    game->skill.sprite = sfSprite_create();
    game->pause.sprite = sfSprite_create();
    game->final.sprite = sfSprite_create();

    game->AT.sprite = sfSprite_create();
    game->CT.sprite = sfSprite_create();
    game->KT.sprite = sfSprite_create();
    game->TT.sprite = sfSprite_create();
}

void my_create_texture(s_game *game)
{
    game->menu.texture = sfTexture_createFromFile("img/menu.png", NULL);
    game->backgr.texture = sfTexture_createFromFile("img/gr/GGfull.png", NULL);
    game->monster.texture = sfTexture_createFromFile("img/enemy/m.png", NULL);
    game->castle.texture = sfTexture_createFromFile("img/castle.png", NULL);
    game->all_tower.texture = sfTexture_createFromFile("img/tower.png", NULL);
    game->skill.texture = sfTexture_createFromFile("img/skills.png", NULL);
    game->pause.texture = sfTexture_createFromFile("img/pause.png", NULL);
    game->final.texture = sfTexture_createFromFile("img/final.png", NULL);
    game->AT.texture = sfTexture_createFromFile("img/AT.png", NULL);
    game->CT.texture = sfTexture_createFromFile("img/CT.png", NULL);
    game->KT.texture = sfTexture_createFromFile("img/KT.png", NULL);
    game->TT.texture = sfTexture_createFromFile("img/TT.png", NULL);
}

void my_create_rectangle_shape(s_game *game)
{
    game->play.rect = sfRectangleShape_create();
    game->exit.rect = sfRectangleShape_create();
    game->play_again.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->play.rect, (sfVector2f){300, 140});
    sfRectangleShape_setSize(game->exit.rect, (sfVector2f){300, 140});
    sfRectangleShape_setSize(game->play_again.rect, (sfVector2f){198, 87});
    game->play.texture = sfTexture_createFromFile("img/play.png", NULL);
    game->exit.texture = sfTexture_createFromFile("img/exit.png", NULL);
    game->play_again.texture = sfTexture_createFromFile("img/pa.png", NULL);
    sfRectangleShape_setTexture(game->play.rect, game->play.texture, sfFalse);
    sfRectangleShape_setTexture(game->exit.rect, game->exit.texture, sfFalse);
    sfRectangleShape_setTexture(game->play_again.rect,
                               game->play_again.texture, sfFalse);
    sfRectangleShape_setPosition(game->play.rect, game->play.pos);
    sfRectangleShape_setPosition(game->exit.rect, game->exit.pos);
    sfRectangleShape_setPosition(game->play_again.rect, game->play_again.pos);
}
