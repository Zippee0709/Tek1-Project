/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for bistromatic project
*/

#include "bistromatic.h"
#include "my.h"

static void my_header(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operator: the symbols of the parentheses ");
    my_putstr("and the 5 operators\n");
    my_putstr("- size_read: number of character to be read\n");
}

int main(int ac, char **av)
{
    bistro_s bistro;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_header();
        return (EXIT_SUCCESS);
    }
    else if (ac != 4) {
        my_putstr_err("Usage: ");
        my_putstr_err(av[0]);
        my_putstr_err(" base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    else {
        my_check_av(av);
        init_bistro(&bistro, av);
        eval_expr(&bistro);
    }
    return (EXIT_SUCCESS);
}
