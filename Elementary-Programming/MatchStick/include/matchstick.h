/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** all protypes and struct for matchstick
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#ifndef READ_SIZE
#define READ_SIZE 5
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define PLAYER 1
#define AI     2

typedef struct s_game
{
    char **map;
    char *s;
    int size;
    int length;
    int nb_stick;
    int user_line;
    int user_stick;
    int ai_line;
    int ai_stick;
    int status;
    int result;
    int evt;
}s_game;

typedef struct s_ai
{
    int *tab;
    int nb;
    int pow;
    int pow_1;
    int pow_2;
    int pow_4;
    int pow_8;
    int pow_16;
    int pow_32;
    int pow_64;
}s_ai;

int init_ai(s_ai *ai);
int init_game(s_game *game, char **av);
int *init_pow_tab(s_ai *ai);
char **init_map(int size, int length);

void update_game(s_game *game);
int game_func(s_game *game);
int matchstick(s_game *game, char **av);

int my_check_stick_on_map(char **map);
void change_turn(s_game *game);
void my_check_winner(s_game *game);
int my_check_result(s_game *game);

void fill_first_or_last_line(s_game *game, int i);
void fill_other_line(s_game *game, int i, int space, int bar);
void my_fill_tab(s_game *game);

int my_line_error(int size);
int my_stick_error(int stick, int size);
void print_line_err(void);
void print_stick_err(int max_value);

int my_get_line(s_game *game);
int my_get_last_stick_pos(char **map, int line);
int my_get_max_stick(char **map, int line);
int my_get_stick(s_game *game);

int my_ai_marienbad(s_game *game);
void winner(s_game *game);
void looser(s_game *game);

int pow_1(int *nb, s_ai *ai);
int pow_2(int *nb, s_ai *ai);
int pow_4(int *nb, s_ai *ai);
void take_1(s_game *game);
void take_2(s_game *game);
void take_4(s_game *game);

int my_search_nb_stick_on_map(char **map, int nb);
void my_ai_update(s_game *game);
int my_check_odd(s_game *game, s_ai *ai);
int my_find_nb_stick(s_game *game, s_ai *ai);
void my_get_final_stick(s_game *game, s_ai *ai);
void my_ai_take_stick(s_game *game, int i);

void my_print_map(char **map);
void my_print_turn(int evt);
int my_user_print_line(s_game *game);
int my_user_print_stick(s_game *game);
int my_print_all(s_game *game);

void my_print_game_info(s_game *game);

char *get_next_line(int fd);

void my_free_dtab(char **tab);
#endif
