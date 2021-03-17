/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for BSQ project
*/

#include "my.h"
#include "bsq.h"

void help(char *av)
{
    if (av[0] == '-' && av[1] == 'h') {
        my_putstr("Description :\n");
        my_putstr("Find the biggest square in the map\n");
        my_putstr("\nUsage : ./bsq map_location\n");
        my_putstr("Map only support 'o' and 'x'\n");
        my_putstr("all of the lines will be the");
        my_putstr(" same length (except the first one)\n");
        my_putstr("first line contains the number of");
        my_putstr(" lines on the board (and only that)\n");
        exit(EXIT_SUCCESS);
    }
}

void init_bsq(bsq_s *bsq, char *av)
{
    char *str = NULL;

    bsq->index = 0;
    str = read_file(av);
    my_check_str(str);
    bsq->width = my_getnbr(str);
    bsq->lenght = my_get_lenght(str);
    bsq->x = 0;
    bsq->y = 0;
    my_double_malloc(bsq);
    my_str_to_word_tab(bsq, str);
    free(str);
    my_bsq_algorithm(bsq);
    my_print_tab(bsq->tab);
    my_free_tab(bsq->tab);
}

int main(int ac, char **av)
{
    bsq_s bsq;

    if (ac != 2) {
        my_putstr_err("Error: No enough argument\n");
        exit(84);
    }
    help(av[1]);
    init_bsq(&bsq, av[1]);
}
