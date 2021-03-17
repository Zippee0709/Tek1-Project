/*
** EPITECH PROJECT, 2019
** do_debug_mode.c
** File description:
** debug mode
*/

#include "tetris.h"
#include "my.h"

int do_debug_mode(tetris_t *tetris)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_option(tetris);
    recup_tetriminos_data(tetris);
    print_debug(tetris->tetriminos);
    my_putstr("Press any key to start Tetris\n");
    if (wait_input() == -1)
        return (-1);
    return 0;
}
