/*
** EPITECH PROJECT, 2019
** draw.c
** File description:
** draw.c
*/

#include "my_defender.h"

void draw_menu(s_game *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->play.rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->exit.rect, NULL);
}

void draw_ground_dlist(Dlist *list, s_game *game)
{
    Dlist_node *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->begin;
    while (tmp != NULL) {
        sfSprite_setTexture(tmp->obj.sprite, tmp->obj.texture, sfTrue);
        sfSprite_setPosition(tmp->obj.sprite, tmp->obj.pos);
        sfRenderWindow_drawSprite(game->window, tmp->obj.sprite, NULL);
        tmp = tmp->next;
    }
}

void draw_sprite_dlist(Dlist *list, s_game *game)
{
    Dlist_node *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->begin;
    while (tmp != NULL) {
        sfSprite_setTexture(tmp->obj.sprite, tmp->obj.texture, sfTrue);
        sfSprite_setTextureRect(tmp->obj.sprite, tmp->obj.rect);
        sfSprite_setPosition(tmp->obj.sprite, tmp->obj.pos);
        sfRenderWindow_drawSprite(game->window, tmp->obj.sprite, NULL);
        tmp = tmp->next;
    }
}

void draw_error(s_game *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock_text);
    float seconds = time.microseconds / 1000000.0;

    if (game->error == ERROR_TOWER && seconds < 2)
        sfRenderWindow_drawText(game->window, game->text.text_tower, NULL);
    else if (game->error == ERROR_SKILL && seconds < 2)
        sfRenderWindow_drawText(game->window, game->text.text_skill, NULL);
    else {
        sfClock_restart(game->clock_text);
        game->error = -1;
    }
}

void draw_game(s_game *game)
{
    sfSprite_setPosition(game->castle.sprite, game->castle.pos);
    sfRenderWindow_drawSprite(game->window, game->backgr.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->castle.sprite, NULL);
    draw_ground_dlist(game->base_gr, game);
    draw_ground_dlist(game->gr, game);
    draw_ground_dlist(game->tower_map, game);
    draw_sprite_dlist(game->enemies, game);
    draw_ground_dlist(game->shots, game);
    if (game->tower_status == 1)
        sfRenderWindow_drawSprite(game->window, game->all_tower.sprite, NULL);
    else if (game->tower_status == 2)
        sfRenderWindow_drawSprite(game->window, game->skill.sprite, NULL);
    draw_error(game);
    draw_score(game);
    draw_castle_life(game);
}

