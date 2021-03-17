/*
** EPITECH PROJECT, 2018
** my_hunter.h
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct hunter_s
{
    sfSprite *s_duck;
    sfTexture *t_duck;
    sfVector2f s_pos;
    sfIntRect rect_duck;
    
    sfSprite *s_back;
    sfTexture *t_back;

    sfSprite *s_play;
    sfTexture *t_play;
    sfVector2f p_pos;

    sfSprite *s_final;
    sfTexture *t_final;
    
    sfClock *clock;
    sfTime time;
    float second;
    
    sfVector2f move;
    sfVector2i mouse_pos;

    int status;
    sfEvent event;
    sfFont *font;
    sfText *text;
    sfText *text_score;
    sfText *text_final;
    
    int score;
    int life;
}hunter_s;

void my_putchar(char c);
void my_putstr(char *str);
void my_print_score(hunter_s *hunter);

void init_texture_sprite(hunter_s *hunter);
void init_struct_value(hunter_s *hunter);
void init_text(hunter_s *hunter);
void init_all(hunter_s *hunter);

void main_run(sfRenderWindow *window, hunter_s *hunter);

void my_respawn_bird(hunter_s *hunter);
void manage_mouse_click(hunter_s *hunter);
void analyse_event(sfRenderWindow *window, hunter_s *hunter);

void set_sprite_texture(hunter_s *hunter);
void set_rect(hunter_s *hunter);
void draw_menu(sfRenderWindow *window, hunter_s *hunter);
void draw_sprite(sfRenderWindow *window, hunter_s *hunter);
void draw_final(sfRenderWindow *window, hunter_s *hunter);
void my_clock(hunter_s *hunter);

void my_change_movement(hunter_s *hunter);
void my_set_pos(hunter_s *hunter);
void my_set_score(hunter_s *hunter, sfText *text);

char *my_int_convert_str(int nb);

void my_destroy(hunter_s *hunter, sfRenderWindow *window);

#endif
