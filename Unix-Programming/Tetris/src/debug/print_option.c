/*
** EPITECH PROJECT, 2019
** print_option.c
** File description:
** print game option
*/

#include "my.h"
#include "tetris.h"

void print_escape_sequence(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 27)
            my_putstr("^E");
        else
            my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}

void print_option_next(tetris_t *tetris)
{
    my_putstr("Next :  ");
    if (tetris->opt->next)
        my_putstr("No\n");
    else
        my_putstr("Yes\n");
    my_putstr("Level :  ");
    my_put_nbr(tetris->opt->level);
    my_putchar('\n');
    my_putstr("Size :  ");
    my_put_nbr(tetris->opt->size.x);
    my_putchar('*');
    my_put_nbr(tetris->opt->size.y);
    my_putchar('\n');
}

void print_option_flw(tetris_t *tetris)
{
    if (my_strcmp(tetris->opt->drop, " ") == 0)
        my_putstr("Key Drop :  (space)\n");
    else {
        my_putstr("Key Drop :  ");
        print_escape_sequence(tetris->opt->drop);
    }
    if (my_strcmp(tetris->opt->quit, " ") == 0)
        my_putstr("Key Quit :  (space)\n");
    else {
        my_putstr("Key Quit :  ");
        print_escape_sequence(tetris->opt->quit);
    }
    if (my_strcmp(tetris->opt->pause, " ") == 0)
        my_putstr("Key pause :  (space)\n");
    else {
        my_putstr("Key Pause :  ");
        print_escape_sequence(tetris->opt->pause);
    }
    print_option_next(tetris);
}

void print_option(tetris_t *tetris)
{
    if (my_strcmp(tetris->opt->left, " ") == 0) {
        my_putstr("Key Left :  (space)\n");
    } else {
        my_putstr("Key Left :  ");
        print_escape_sequence(tetris->opt->left);
    }
    if (my_strcmp(tetris->opt->right, " ") == 0)
        my_putstr("Key Right :  (space)\n");
    else {
        my_putstr("Key Right :  ");
        print_escape_sequence(tetris->opt->right);
    }
    if (my_strcmp(tetris->opt->turn, " ") == 0)
        my_putstr("Key Turn :  (space)\n");
    else {
        my_putstr("Key Turn :  ");
        print_escape_sequence(tetris->opt->turn);
    }
    print_option_flw(tetris);
}
