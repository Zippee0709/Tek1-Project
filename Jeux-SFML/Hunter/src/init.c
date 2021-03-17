/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** all usefull function
*/

#include "my_hunter.h"

void init_text(hunter_s *hunter)
{
    sfVector2f text_pos = {0, 0};
    sfVector2f text_score_pos = {170, 0};
    sfVector2f text_final_pos = {910, 450};
    char *str = my_int_convert_str(hunter->score);

    sfText_setString(hunter->text, "Score : ");
    sfText_setString(hunter->text_score, str);
    sfText_setString(hunter->text_final, str);
    sfText_setFont(hunter->text, hunter->font);
    sfText_setFont(hunter->text_score, hunter->font);
    sfText_setFont(hunter->text_final, hunter->font);
    sfText_setCharacterSize(hunter->text, 50);
    sfText_setCharacterSize(hunter->text_score, 50);
    sfText_setCharacterSize(hunter->text_final, 100);
    sfText_setPosition(hunter->text, text_pos);
    sfText_setPosition(hunter->text_score, text_score_pos);
    sfText_setPosition(hunter->text_final, text_final_pos);
    sfText_setColor(hunter->text_final, sfBlue);
}

void init_texture_sprite(hunter_s *hunter)
{
    hunter->t_duck = sfTexture_createFromFile("sprit/duck.png", NULL);
    hunter->t_back = sfTexture_createFromFile("sprit/back.png", NULL);
    hunter->t_play = sfTexture_createFromFile("sprit/play.png", NULL);
    hunter->t_final = sfTexture_createFromFile("sprit/final.png", NULL);
    hunter->font = sfFont_createFromFile("sprit/font.ttf");
    hunter->s_duck = sfSprite_create();
    hunter->s_back = sfSprite_create();
    hunter->s_play = sfSprite_create();
    hunter->s_final = sfSprite_create();
    hunter->text = sfText_create();
    hunter->text_score = sfText_create();
    hunter->text_final = sfText_create();
}

void init_struct_value(hunter_s *hunter)
{
    hunter->rect_duck.top = 0;
    hunter->rect_duck.left = 0;
    hunter->rect_duck.width = 110;
    hunter->rect_duck.height = 110;
    hunter->move.x = 0.8;
    hunter->move.y = 0;
    hunter->status = 0;
    hunter->score = 0;
    hunter->life = 1;
}

void init_all(hunter_s *hunter)
{
    init_texture_sprite(hunter);
    init_struct_value(hunter);
    init_text(hunter);
    set_sprite_texture(hunter);
    my_set_pos(hunter);
    set_rect(hunter);
    hunter->clock = sfClock_create();
}
