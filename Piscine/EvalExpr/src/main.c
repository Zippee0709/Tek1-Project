/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for evalexpr
*/

#include "my.h"
#include "evalexpr.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
