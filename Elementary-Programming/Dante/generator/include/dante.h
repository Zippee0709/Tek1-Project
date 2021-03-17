/*
** EPITECH PROJECT, 2019
** dante.h
** File description:
** dante.h
*/

#ifndef DANTE_H
#define DANTE_H

#include "struct.h"
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int (*neighbour)(Pos_t p, Cell_t **map, int nb);
typedef int (*myrand)(Dante_t *dante, Cell_t **map, Pos_t *p);

int my_init_dante(Dante_t *dante, int ac, char **av);
void my_init_pos(Pos_t *pos, int max_x, int max_y);

int my_get_nb_unvisited_cell(Cell_t **map, Pos_t pos);
int my_get_success_road_hor(Cell_t **map, int max_x, int y);
int my_get_success_road_ver(Cell_t **map, int max_x, int y);
int my_get_wall_in_map(Cell_t **map, Pos_t pos);

int my_check_neighbour(Dante_t *dante, Cell_t *map, Cell_t *back);
int my_check_is_wall(Cell_t **map, int x, int y);
void my_check_last_line(Cell_t **map, Pos_t *p);
void my_check_in_list(Dlist_t *list, Dante_t *dante);

int check_up(Pos_t p, Cell_t **map, int nb);
int check_down(Pos_t p, Cell_t **map, int nb);
int check_left(Pos_t p, Cell_t **map, int nb);
int check_right(Pos_t p, Cell_t **map, int nb);
int my_check_neighbour_avaible(Dante_t *dante);

void my_gen_perfect_map(Dante_t *dante);
void my_gen_imperfect_map(Cell_t **map, Pos_t *p, int nb_wall);

void my_set_wall_in_map(Cell_t *map);
void my_set_road_in_map(Cell_t *map);
void my_set_exit_cell(Cell_t **map, Pos_t *p);

void my_random_neighbour(Dante_t *dante, Cell_t **map, Pos_t *p);

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_error_size(int x, int y);
int my_error_type(Dante_t *dante, int ac, char **av);

Dlist_t *add_end_list(Dlist_t *list, Pos_t pos);
Dlist_t *pop_end_list(Dlist_t *list);
Dlist_t *pop_begin_list(Dlist_t *list);

void my_print_map(Cell_t **map, Pos_t pos);
void my_free_map(Cell_t **map, Pos_t pos);
void my_free_dlist(Dlist_t *list);

#endif
