/*
** EPITECH PROJECT, 2019
** init2.c
** File description:
** init2.c
*/

#include "my_defender.h"

void init_text_size_pos(s_game *game)
{
    sfVector2f pos = {480, 270};
    sfVector2f score = {1700, 0};

    sfText_setCharacterSize(game->text.text_tower, 50);
    sfText_setCharacterSize(game->text.text_skill, 50);
    sfText_setCharacterSize(game->text.text_score, 30);
    sfText_setCharacterSize(game->text.score, 30);
    sfText_setPosition(game->text.text_tower, pos);
    sfText_setPosition(game->text.text_skill, pos);
    sfText_setPosition(game->text.text_score, score);
    score.x = score.x + 130;
    sfText_setPosition(game->text.score, score);
    sfText_setColor(game->text.text_tower, sfRed);
    sfText_setColor(game->text.text_skill, sfRed);
    sfText_setColor(game->text.text_score, sfYellow);
    sfText_setColor(game->text.score, sfYellow);
}

void init_text(s_game *game)
{
    char *str_score = my_int_convert_str(game->score);

    game->font = sfFont_createFromFile("img/256.ttf");
    game->text.text_tower = sfText_create();
    game->text.text_skill = sfText_create();
    game->text.text_score = sfText_create();
    game->text.score = sfText_create();
    game->text.castle = sfText_create();
    game->text.castle_life = sfText_create();
    sfText_setString(game->text.text_tower, "The tower can't be place here!\n");
    sfText_setString(game->text.text_skill, "The tower reach maximum level!\n");
    sfText_setString(game->text.text_score, "Score : ");
    sfText_setString(game->text.score, str_score);
    sfText_setFont(game->text.text_tower, game->font);
    sfText_setFont(game->text.text_skill, game->font);
    sfText_setFont(game->text.text_score, game->font);
    sfText_setFont(game->text.score, game->font);
    init_text_size_pos(game);
}

void init_pos(s_game *game)
{
    game->play.pos.x = 790;
    game->play.pos.y = 600;
    game->exit.pos.x = 790;
    game->exit.pos.y = 750;
    game->pause.pos.x = 300;
    game->pause.pos.y = 800;
    game->monster.pos.x = 155;
    game->monster.pos.y = 0;
    game->monster.rect.left = 0;
    game->monster.rect.top = 0;
    game->monster.rect.width = 80;
    game->monster.rect.height = 60;
    game->castle.pos.x = 1280;
    game->castle.pos.y = 660;
    game->all_tower.pos.x = 1400;
    game->all_tower.pos.y = 100;
    game->skill.pos.x = 1600;
    game->skill.pos.y = 400;
}

void init_float_rect(sfFloatRect *rect, sfVector2f min, sfVector2f max)
{
    rect->left = min.x;
    rect->top = min.y;
    rect->width = max.x;
    rect->height = max.y;
}

void init_music(s_game *game)
{
    game->music.game = sfMusic_createFromFile("img/music/level.wav");
    game->music.start = sfMusic_createFromFile("img/music/newgame.wav");
    game->music.tower = sfMusic_createFromFile("img/music/towerBuilt.wav");
    game->music.fire = sfMusic_createFromFile("img/music/fireball.wav");
    game->music.arrow = sfMusic_createFromFile("img/music/arrow.wav");
    game->music.rock = sfMusic_createFromFile("img/music/rock.wav");
    game->music.ninja = sfMusic_createFromFile("img/music/hit.wav");
    game->music.game_over = sfMusic_createFromFile("img/music/gameover.wav");
    sfMusic_setLoop(game->music.game, sfTrue);
}
