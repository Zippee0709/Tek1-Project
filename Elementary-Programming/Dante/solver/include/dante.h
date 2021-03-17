/*
** EPITECH PROJECT, 2019
** dante.h
** File description:
** dante.h
*/

#ifndef DANTE_H
#define DANTE_H

typedef struct s_solve
{
    int x;
    int y;
    int xmax;
    int ymax;
} solve;

typedef struct s_map
{
    char *buf;
    char **map;
} s_map;

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void print_map(char **map, solve *s);
char *my_size(char *av);
int nb_lane(char *buffer);
void display_map(char **map);
char **filled_map(char **map, char *buf);
char **alloc_map(char *av, s_map *map);
int check_star(s_map *map, solve *s);
void pos_max(solve *s, s_map *map);
int change_flag(s_map *map, solve *s);
char **find_path(s_map *map, solve *s);
int go_back(s_map *map, solve *s);
int check_next_down(s_map *map, solve *s);
int check_next_right(s_map *map, solve *s);

#endif
