/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** all usefull function for run sokoban game
*/

#include "my.h"
#include "sokoban.h"

void my_game_func(sokoban_s *sokoban, int *ch)
{
    clear();
    tab_func_move(sokoban, *ch);
    my_printw_tab(sokoban->map);
    refresh();
    *ch = getch();
}

void my_game(sokoban_s *sokoban)
{
    int ch = 0;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);

    while (ch != KEY_BACKSPACE) {
        my_game_func(sokoban, &ch);
        if (my_check_end_game(sokoban->map, sokoban) == 0) {
            sokoban->status = 0;
            break;
        }
        else if (my_check_x_block(sokoban->map, sokoban) == 1) {
            sokoban->status = 1;
            break;
        }
    }
    endwin();
}
