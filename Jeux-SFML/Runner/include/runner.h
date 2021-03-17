/*
** EPITECH PROJECT, 2018
** runner.h
** File description:
** all prototypes and struct for my_runner
*/

#ifndef RUNNER_H
#define RUNNER_H

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_obj
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f move_speed;
    sfVector2f pos;
    sfIntRect rect;
}s_obj;

typedef struct s_game
{
    sfEvent event;
    s_obj *tab;
    s_obj monster;
    s_obj monster1;
    s_obj monster2;
    s_obj sprite;
    s_obj sky_bg;
    s_obj tree_bg;
    s_obj cloud_bg;
    s_obj rock_bg;
    s_obj play_bg;
    s_obj replay_bg;
    char *map;
    sfClock *clock;
    sfClock *sclock;
    sfClock *jclock;
    sfTime time;
    float seconds;
    float p_seconds;
    sfVector2f move_speed;
    int m1;
    int m2;
    int m3;
    int i;
    int jump;
    char nb_zombie;
    int status;
    int score;
    int life;
}s_game;

void main_run(sfRenderWindow *window, s_game *game);
void run_menu(sfRenderWindow *window, s_game *game);
void run_game(sfRenderWindow *window, s_game *game);

void create_texture(s_game *game);
void create_sprite(s_game *game);
void create_clock_str(s_game *game);
void create_position(s_game *game);
int create_map_from_txt(s_game *game, char const *str);

void move_monster_sprite(s_game *game);
void draw_all_sprite(sfRenderWindow *window, s_game *game);
void draw_all_monster(sfRenderWindow *window, s_game *game);

void check_nb_monster(s_game *game);
void check_colision(s_game *game);

void event_jump(s_game *game);
void analyse_event(sfRenderWindow *window, s_game *game);
void analyse_map(s_game *game, int *i);

void manage_mouse_click(s_game *game);

int init_game(s_game *game, char const *str);
void pending_game(sfRenderWindow *window, s_game *game);
int create_window(char const *str);

void my_putchar(char c);
void my_putstr(char const *str);
void my_putchar_err(char c);
void my_putstr_err(char const *str);
int get_size_with_stat(char const *str);

sfIntRect my_set_rect(int a, int b, int c, int d);
void set_all_rect(s_game *game);
void set_texture(s_game *game);
void set_texture_rect(s_game *game);
void set_all_position(s_game *game);

void move_rect(sfIntRect *rect, int offset, int max_value);
void move_background(s_game *game);
void clock_background(s_game *game);
void clock_sprite(s_game *game);

void destroy_sprite(s_game *game);
void destro_texture(s_game *game);
void destroy_all(sfRenderWindow *window, s_game *game);

#endif
