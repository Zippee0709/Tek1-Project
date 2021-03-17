/*
** EPITECH PROJECT, 2019
** lemin.h
** File description:
** lemin.h
*/

#ifndef LEMIN_H
#define LEMIN_H

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct DlistNode
{
    int value;
    int status;
    struct DlistNode *next;
}DlistNode;

typedef struct DlistAnts
{
    int ants_nb;
    int ants_rooms;
    int ants_pos;
    int status;
    struct DlistAnts *next;
}DlistAnts;

typedef struct AdjencyList
{
    DlistNode *begin;
    int length;
}AdjencyList;

typedef struct Graph
{
    int status;
    int nb_vertices;
    AdjencyList *tab;
}Graph;

typedef struct rooms_connect
{
    int room1;
    int room2;
    int link_start;
    int link_end;
    struct rooms_connect *next;
}room_t;

typedef struct Error_t
{
    int start;
    int end;
    int x;
    int y;
}Error_t;

typedef struct Vector_t
{
    int x;
    int y;
}Vector_t;

typedef struct Global_t
{
    char *file;
    char **tab;
    char **tunnels;
    char **rooms;
    int **previous;
    int **status;
    Graph *graph;
    Graph *close;
    DlistAnts *ants;
    int start;
    int end;
    int nb_ants;
    int nb_road;
}Global_t;

Graph *new_graph(int vertices, int status);
DlistNode *add_node(int value);
void add_edge(Graph *graph, int src, int dest);
void add_value(Graph *graph, int src, int dest);
DlistAnts *add_ants(DlistAnts *list, int ants_nb, int ants_rooms);
void print_graph(Graph *graph);
void print_list_ants(DlistAnts *ants);
void free_graph(Graph *graph);
void print_list_ants_status(DlistAnts *ants, int start, int end);

char **my_malloc_dtab(int height, int length);
int **my_malloc_int_dtab(int height, int length);
void my_init_new_graph(Global_t *global);
char **my_stock_all_tunnels(char **tab);
char **my_stock_all_rooms(char **tab, int size);

int my_strlen_room(char *str);
char *my_strcpy_room(char *dest, char const *src);
char **find_classic_rooms(char **tab);
int verify_room(char *str);
void alloc_room(char ***room, int y, char **tab, char *ending);
char **find_starts(char **tab);
int find_basic_possibility(Graph *graph, int src, int end);
void my_convert_tunnel_to_connection(Graph *graph, char **tab);
void my_ants_travel(Global_t *global, Graph *close);

char *read_file(int fd);
char *read_file_with_getline(int fd);

int my_check_str_only_nbr(char *str);
int my_check_str_is_tunnel(char *str);

int my_get_nb_vertices(char **str);
int my_get_nb_tunnels(char **str);
int my_get_room(char **str, char *msg);
int my_get_ants_length(DlistAnts *ants);

char **my_clean_tab(char **tab);
void my_show_tab(char **tab);
void my_show_file(char **tab);
void my_show_int_dtab(int **tab);

int check_start(Global_t global, Error_t *error);
int check_end(Global_t global, Error_t *error);
void init_err(Error_t *error);
int check_map(Global_t global, Error_t *error);

Graph *my_dijkstra_pathfinder(Graph *graph, Graph *close, Global_t *global);
void my_free_all(Global_t *global);
void my_free_dtab(char **tab);
void my_free_int_dtab(int **tab);
char **my_free_last_cell(char **tab);
#endif
