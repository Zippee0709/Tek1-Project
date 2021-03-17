/*
** EPITECH PROJECT, 2018
** move_func.c
** File description:
** all usefull move function
*/

#include "my.h"
#include "sokoban.h"

void move_p(sokoban_s *s, int x, int y)
{
    if (s->map[x][y] == '#' || s->map[x][y] == 'X')
        return;
    else if (s->map[x][y] == 'O') {
        my_swap_o(&s->map[s->x][s->y], &s->map[x][y]);
        s->v_o.x = x;
        s->v_o.y = y;
    }
    else {
        my_swap_char(&s->map[s->x][s->y], &s->map[x][y]);
        my_check_o_print(s);
    }
}

void move_x(sokoban_s *s, int x, int y, vector2i *v)
{
    if (s->map[v->x][v->y] == '#')
        return;
    else if (s->map[v->x][v->y] == 'X' && s->map[x][y] != '#') {
        my_swap_char(&s->map[v->x][v->y], &s->map[x][y]);
    }
}

void my_reset(sokoban_s *sokoban)
{
    my_tab_copy(sokoban->map_copy, sokoban->map);
}
