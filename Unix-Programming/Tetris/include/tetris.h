/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** Contient les prototypages de tetris
*/

#ifndef TETRIS
#define TETRIS

#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <dirent.h>
#include <term.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
    char **shape;
    int size;
    int x;
    int y;
}shape_t;

typedef struct game_s {
    int x;
    int y;
    int ch;
    int status;
    int score;
    char **map;
    char **tmp;
    shape_t *tab_shape;
    shape_t current;
    shape_t next;
}game_t;

typedef struct {
    char *name;
    char **forms;
    int size_x;
    int size_y;
    int color;
    bool correct;
}tetrimino_caract_t;

typedef struct size_s {
    int x;
    int y;
}sizegame_t;

typedef struct option_s {
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
    bool next;
    int level;
    sizegame_t size;
}option_t;

typedef struct tetris_s {
    option_t *opt;
    int tetriminos_max;
    tetrimino_caract_t **tetriminos;
    bool debug;
    bool help;
}tetris_t;

typedef int (*tpsf)(game_t *, int, shape_t);

//recup_tetriminos_data.c
int recup_tetriminos_data(tetris_t *tetris);
//read_file.c
int read_file(char *pathfile, tetrimino_caract_t *caract);
//check_tetrimino.c
int check_tetrimino(char *filepath, char *name, tetrimino_caract_t *caract);
//print_tetrimino_data.c
void print_tetrimino_data(tetrimino_caract_t *caract);
void print_debug(tetrimino_caract_t **caract);
//recup_argv.c - recup_argv_flw.c 
int recup_argv(int ac, char **av, tetris_t *tetris);
int recup_argv_switch_flw(int opt, tetris_t *tetris);
//do_debug_mode.c
int do_debug_mode(tetris_t *tetris);
//print_option.c
void print_option(tetris_t *tetris);
int wait_input(void);
int count_occur(char *str, char occur);
void free_tetris(tetris_t *tetris);
void print_help_message(char **argv);

void my_tetris(tetris_t *tetri);
int my_check_shape_pos(shape_t shape, int max_x, int max_y, char **map);
shape_t my_copy_shape(shape_t shape);
shape_t my_get_new_shape(game_t *game);

shape_t my_init_t(int size, int x, int y);
shape_t my_init_square(int size, int x, int y);
shape_t my_init_bar(int size, int x, int y);
int my_init_tab_shape(game_t *shape);
void my_init_game(game_t *game, tetris_t *tetris);

void my_print_game_map(char **map, int x);
void my_print_shape(shape_t shape);
void my_rotate_shape(shape_t *shape);
char **my_strcpy_tab(char **str1, char **str2);
void my_write_shape_in_map(shape_t current, char **map);

int move_down(game_t *game, int action, shape_t tmp);
int move_left(game_t *game, int action, shape_t tmp);
int move_right(game_t *game, int action, shape_t tmp);
int move_rotate(game_t *game, int action, shape_t tmp);

#endif
