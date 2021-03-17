/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>

#define EXIT_ERROR 84

typedef struct vector2i

{
    int x;
    int y;
}vector2i;

typedef struct sokoban
{
    int status;
    int nb_x;
    int x;
    int y;
    int size;
    char *map_s;
    char **map;
    char **map_copy;
    vector2i v_o;
}sokoban_s;

typedef void (*tpf)(sokoban_s *sokoban);

void my_sokoban(char **av, sokoban_s *sokoban);
void help(int ac, char **av);

int get_size_with_stat(char const *str);
char *read_file(char const *str, int size);
char *my_malloc(char const *str);
void my_tab_copy(char **s1, char **s2);

void init_vector(vector2i *v);
void init_sokoban(sokoban_s *sokoban, char const *av);

void my_game(sokoban_s *sokoban);

void move_left(sokoban_s *sokoban);
void move_right(sokoban_s *sokoban);
void move_up(sokoban_s *sokoban);
void move_down(sokoban_s *sokoban);
void tab_func_move(sokoban_s *sokoban, int ch);

void move_p(sokoban_s *sokoban, int x, int y);
void move_x(sokoban_s *sokoban, int x, int y, vector2i *v);
void my_reset(sokoban_s *sokoban);

void my_swap_char(char *a, char *b);
void my_swap_o(char *a, char *b);
int my_count_x(char const *str);

void my_check_o_print(sokoban_s *s);
int my_check_end_game(char **map, sokoban_s *sokoban);
void my_check_map(char const *str);
int my_check_x_pos(char **map, int i, int j);
int my_check_x_block(char **map, sokoban_s *sokoban);

void my_show_word_tab(char **tab);
void my_print_result(int status);
void my_printw_tab(char **tab);
void my_searching_p(sokoban_s *sokoban, char **tab);
void my_free_word_tab(char **tab);

char **my_str_to_word_tab(char const *str);
#endif
