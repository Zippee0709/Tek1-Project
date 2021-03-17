/*
** EPITECH PROJECT, 2019
** fill_map.c
** File description:
** fill map for navy
*/

#include <stdio.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

const int MAP_MAX = 8;
const int LINE_MAX = 4;

void flw_fill_coord(char **pos, coord_t *coord, int i, int j)
{
    switch (j) {
    case 3:
        coord[i].y1 = pos[i][j] - 48 - 1;
        break;
    case 5:
        coord[i].x2 = pos[i][j] - 48 - 1;
        break;
    case 6:
        coord[i].y2 = pos[i][j] - 48 - 1;
        break;
    }
}

void fill_coord(char **pos, coord_t *coord, int i, int j)
{
    switch (j) {
    case 0:
        coord[i].number = pos[i][j];
        break;
    case 2:
        coord[i].x1 = pos[i][j] - 48 - 1;
        break;
    default:
        flw_fill_coord(pos, coord, i, j);
        break;
    }
}

void fill_map(char map[MAP_MAX][MAP_MAX], coord_t *coord, int i, int j)
{
    for (int a = 0; a < LINE_MAX; a++) {
        if (j >= coord[a].x1 && i >= coord[a].y1 &&
            j <= coord[a].x2 && i <= coord[a].y2) {
            map[i][j] = coord[a].number;
        }
    }
}

void fill_map_null(char map[MAP_MAX][MAP_MAX])
{
    for (int i = 0; i < MAP_MAX; i++) {
        for (int j = 0; j < MAP_MAX; j++) {
            map[i][j] = '.';
        }
    }
}

int start_fill_map(char **pos, char map[MAP_MAX][MAP_MAX])
{
    coord_t *coord = malloc(sizeof(coord_t) * (LINE_MAX));

    for (int i = 0; pos[i] != NULL; i++) {
        for (int j = 0; pos[i][j] != '\0'; j++) {
            fill_coord(pos, coord, i, j);
        }
    }
    fill_map_null(map);
    for (int i = 0; i < MAP_MAX; i++) {
        for (int j = 0; j < MAP_MAX; j++) {
            fill_map(map, coord, i, j);
        }
    }
    return (0);
}
