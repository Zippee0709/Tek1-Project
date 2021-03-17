/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_T

enum Bool_t
{
    FALSE,
    TRUE,
};

enum Type_maze
{
    IMPERFECT,
    PERFECT,
};

typedef struct pos_t
{
    int x;
    int y;
    int max_x;
    int max_y;
}Pos_t;

typedef struct DlistNode_t
{
    Pos_t pos;
    struct DlistNode_t *next;
    struct DlistNode_t *back;
}DlistNode_t;

typedef struct Dlist_t
{
    int length;
    int status;
    DlistNode_t *begin;
    DlistNode_t *end;
}Dlist_t;

typedef struct cell_t
{
    char c;
    int visited;
}Cell_t;

typedef struct dante_t
{
    int type;
    Pos_t pos;
    Dlist_t *list;
    Cell_t **map;
}Dante_t;

#endif
