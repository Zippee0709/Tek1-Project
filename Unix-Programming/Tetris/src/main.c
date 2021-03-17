/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of tetris
*/

#include "tetris.h"
#include "my.h"

void initialize_struct_tetris(tetris_t *tetris)
{
    setupterm(NULL, 0, NULL);
    tetris->opt = malloc(sizeof(option_t));
    tetris->opt->level = 1;
    tetris->opt->left = tigetstr("kcub1");
    tetris->opt->right = tigetstr("kcuf1");
    tetris->opt->turn = tigetstr("kcuu1");
    tetris->opt->drop = tigetstr("kcud1");
    tetris->opt->quit = "q";
    tetris->opt->pause = " ";
    tetris->opt->size.y = 10;
    tetris->opt->size.x = 20;
    tetris->opt->next = false;
    tetris->debug = false;
    tetris->help = false;
}

int init_ncurses(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    clear();
    refresh();
    return (0);
}

int check_tetriminos_existence(void)
{
    DIR *tetriminos = opendir("tetriminos/");

    if (tetriminos == NULL) {
        my_putstr_fd(2, "Error, tetriminos directory doesn't exist.\n");
        return (-1);
    }
    return (0);
}

void start_game(tetris_t *tetris)
{
    init_ncurses();
    my_tetris(tetris);
    free_tetris(tetris);
    endwin();
}

int main(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    if (check_tetriminos_existence() == -1)
        return 84;
    initialize_struct_tetris(tetris);
    if (recup_argv(ac, av, tetris) == -1)
        return 84;
    if (tetris->help == true) {
        print_help_message(av);
        return (0);
    }
    if (tetris->debug == true) {
        if (do_debug_mode(tetris) == -1)
            return (84);
    } else
        recup_tetriminos_data(tetris);
    start_game(tetris);
    return (0);
}
