/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all calculate func
*/

#include "my.h"

void my_add(int nb1, int nb2)
{
    int res = nb1 + nb2;
    my_put_nbr(res);
    my_putchar('\n');
}

void my_sous(int nb1, int nb2)
{
    int res = nb1 - nb2;
    my_put_nbr(res);
    my_putchar('\n');
}

void my_mul(int nb1, int nb2)
{
    int res = nb1 * nb2;
    my_put_nbr(res);
    my_putchar('\n');
}

void my_div(int nb1, int nb2)
{
    int res = 0;

    if (nb1 == 0 || nb2 == 0)
        my_putstr("Stop: division by zero\n");
    else {
        res = nb1 / nb2;
        my_put_nbr(res);
        my_putchar('\n');
    }
}

void my_mod(int nb1, int nb2)
{
    int res = 0;

    if (nb1 == 0 || nb2 == 0)
        my_putstr("Stop: modulo by zero\n");
    else {
        res = nb1 % nb2;
        my_put_nbr(res);
        my_putchar('\n');
    }
}
