/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** my main for do_op
*/

#include "my.h"

int do_op(char *s1, char *sign, char *s2);

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    do_op(av[1], av[2], av[3]);
    return (0);
}
