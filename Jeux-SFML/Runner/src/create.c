/*
** EPITECH PROJECT, 2018
** create.c
** File description:
** all usefull create function
*/

#include "runner.h"

void create_texture(s_game *game)
{
    game->sky_bg.texture = sfTexture_createFromFile("img/sky.png", NULL);
    game->tree_bg.texture = sfTexture_createFromFile("img/tree.png", NULL);
    game->cloud_bg.texture = sfTexture_createFromFile("img/cloud.png", NULL);
    game->rock_bg.texture = sfTexture_createFromFile("img/rocks.png", NULL);
    game->play_bg.texture = sfTexture_createFromFile("img/play.png", NULL);
    game->replay_bg.texture = sfTexture_createFromFile("img/final.png", NULL);
    game->sprite.texture = sfTexture_createFromFile("img/sprite.png", NULL);
    game->monster.texture = sfTexture_createFromFile("img/zombie.png", NULL);
    game->monster1.texture = sfTexture_createFromFile("img/zombie.png", NULL);
    game->monster2.texture = sfTexture_createFromFile("img/zombie.png", NULL);
}

void create_sprite(s_game *game)
{
    game->sky_bg.sprite = sfSprite_create();
    game->tree_bg.sprite = sfSprite_create();
    game->cloud_bg.sprite = sfSprite_create();
    game->rock_bg.sprite = sfSprite_create();
    game->play_bg.sprite = sfSprite_create();
    game->replay_bg.sprite = sfSprite_create();
    game->sprite.sprite = sfSprite_create();
    game->monster.sprite = sfSprite_create();
    game->monster1.sprite = sfSprite_create();
    game->monster2.sprite = sfSprite_create();
}

void create_position(s_game *game)
{
    game->i = 0;
    game->status = 0;
    game->jump = 0;
    game->life = 1;
    game->move_speed.x = -5;
    game->move_speed.y = -0;
    game->sprite.pos.x = 100;
    game->sprite.pos.y = 825;
    game->play_bg.pos.x = 860;
    game->play_bg.pos.y = 700;
    game->monster.pos.x = 2000;
    game->monster.pos.y = 825;
    game->monster1.pos = game->monster.pos;
    game->monster1.pos.x = game->monster.pos.x + 200;
    game->monster2.pos = game->monster.pos;
    game->monster2.pos.x = game->monster.pos.x + 400;
}

int create_map_from_txt(s_game *game, char const *str)
{
    int size;
    int fd = open(str, O_RDONLY);

    if ((size = get_size_with_stat(str)) == -1)
        return (-1);
    game->map = malloc(sizeof(char) * (size + 1));
    if (read(fd, game->map, size) < 0) {
        my_putstr_err("Error : read file failed\n");
        return (-1);
    }
    game->map[size] = '\0';
    close(fd);
    return (0);
}

void create_clock_str(s_game *game)
{
    game->clock = sfClock_create();
    game->sclock = sfClock_create();
    game->jclock = sfClock_create();
}
