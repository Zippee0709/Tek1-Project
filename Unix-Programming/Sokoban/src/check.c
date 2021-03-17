/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** all usefull function to check
*/

#include "my.h"
#include "sokoban.h"

void my_check_o_print(sokoban_s *s)
{
    if (s->v_o.x == -1 && s->v_o.y == -1)
        return;
    else if (s->map[s->v_o.x][s->v_o.y] != 'X' ||
            s->map[s->v_o.x][s->v_o.y] != 'P') {
        s->map[s->v_o.x][s->v_o.y] = 'O';
        init_vector(&s->v_o);
    }
}

int my_check_end_game(char **map, sokoban_s *sokoban)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == 'O')
                return (1);
            else if (sokoban->v_o.x != -1 && sokoban->v_o.y != -1)
                return (1);
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (0);
}

void my_check_map(char const *str)
{
    int i = 0;
    int nb_o = 0;
    int nb_x = 0;

    while (str[i] != '\0') {
        if (str[i] == 'O')
            nb_o = nb_o + 1;
        else if (str[i] == 'X')
            nb_x = nb_x + 1;
        i = i + 1;
    }
    if (nb_x != nb_o) {
        my_putstr_err("Error : Invalid map\n");
        exit(EXIT_ERROR);
    }
}

int my_check_x_pos(char **map, int i, int j)
{
    if (map[i][j] == 'X') {
        if ((map[i - 1][j] == '#' && map[i][j - 1] == '#') ||
            (map[i - 1][j] == '#' && map[i][j + 1] == '#') ||
            (map[i + 1][j] == '#' && map[i][j - 1] == '#') ||
            (map[i + 1][j] == '#' && map[i][j + 1] == '#'))
            return (1);
    }
    return (0);
}

int my_check_x_block(char **map, sokoban_s *sokoban)
{
    int i = 0;
    int j = 0;
    int status = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (my_check_x_pos(map, i, j) == 1)
                status = status + 1;
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    if (status == sokoban->nb_x)
        return (1);
    return (0);
}
