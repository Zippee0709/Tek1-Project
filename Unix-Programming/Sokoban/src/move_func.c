/*
** EPITECH PROJECT, 2018
** move_func.c
** File description:
** all usefull move function
*/

#include "my.h"
#include "sokoban.h"

void move_left(sokoban_s *sokoban)
{
    vector2i v;

    my_searching_p(sokoban, sokoban->map);
    v.x = sokoban->x;
    v.y = sokoban->y - 1;
    move_x(sokoban, sokoban->x, sokoban->y - 2, &v);
    move_p(sokoban, sokoban->x, sokoban->y - 1);
}

void move_right(sokoban_s *sokoban)
{
    vector2i v;

    my_searching_p(sokoban, sokoban->map);
    v.x = sokoban->x;
    v.y = sokoban->y + 1;
    move_x(sokoban, sokoban->x, sokoban->y + 2, &v);
    move_p(sokoban, sokoban->x, sokoban->y + 1);
}

void move_up(sokoban_s *sokoban)
{
    vector2i v;

    my_searching_p(sokoban, sokoban->map);
    v.x = sokoban->x - 1;
    v.y = sokoban->y;
    move_x(sokoban, sokoban->x - 2, sokoban->y, &v);
    move_p(sokoban, sokoban->x - 1, sokoban->y);
}

void move_down(sokoban_s *sokoban)
{
    vector2i v;

    my_searching_p(sokoban, sokoban->map);
    v.x = sokoban->x + 1;
    v.y = sokoban->y;
    move_x(sokoban, sokoban->x + 2, sokoban->y, &v);
    move_p(sokoban, sokoban->x + 1, sokoban->y);
}

void tab_func_move(sokoban_s *sokoban, int ch)
{
    int i = 0;
    int tab_key[4] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN};
    tpf tab_func[4] = {move_left, move_right, move_up, move_down};

    while (tab_key[i] != '\0') {
        if (tab_key[i] == ch)
            (*tab_func[i])(sokoban);
        else if (ch == 32)
            my_reset(sokoban);
        i = i + 1;
    }
}
