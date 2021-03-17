/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** all init function
*/

#include "my_defender.h"

void init_game_window(s_game *game)
{
    game->mode.width = 1920;
    game->mode.height = 1080;
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "My_defender",
                                        sfResize | sfClose, NULL);
    game->clock = sfClock_create();
    game->clock_monster = sfClock_create();
    game->clock_text = sfClock_create();
    game->clock_score = sfClock_create();
    game->clock_shots = sfClock_create();
    game->fps = 0;
}

void init_game_img(s_game *game)
{
    my_create_sprite(game);
    my_create_texture(game);
    my_create_ground_sprite(&game->ground);
    my_create_ground_texture(&game->ground);
    my_create_shots_texture(&game->shots_s);
    my_create_rectangle_shape(game);
    my_set_texture(game);
    my_set_position(game);
}

void init_game_value(s_game *game)
{
    game->status = MENU;
    game->is_reset = sfTrue;
    game->tower_status = 0;
    game->score = 0;
    game->error = -1;
    game->castle_life = 1000;
    init_pos(game);
}

void init_game_map(s_game *game)
{
    char *str = create_map_from_txt("img/map.txt");
    game->map = my_str_to_word_tab(str);
    game->gr = NULL;
    game->base_gr = NULL;
    game->enemies = NULL;
    game->shots = NULL;
    game->tower_map = NULL;
    game->gr = my_fill_dlist_ground(game, game->map, 'G', game->gr);
    game->base_gr = my_fill_dlist_ground(game, game->map, '0', game->base_gr);
    free(str);
}

void init_game(s_game *game)
{
    init_game_window(game);
    init_game_value(game);
    init_game_img(game);
    init_game_map(game);
    init_text(game);
    init_text_again(game);
    init_music(game);
}
