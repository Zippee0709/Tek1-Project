/*
** EPITECH PROJECT, 2018
** my_put_nbr_base.c
** File description:
** my_put_nbr_base.c
*/

#include "../my.h"
#include "printf.h"

int my_put_nbr_base(int nb, char *base)
{
    int res = 0;
    int save = 1;
    int size_base = my_strlen(base);

    if (nb < 0)
        nb = nb * -1;
    while ((nb / save) >= size_base)
        save = save * size_base;
    while (save > 0) {
        res = (nb /save) % size_base;
        save = save / size_base;
        my_putchar(base[res]);
    }
    return (0);
}
