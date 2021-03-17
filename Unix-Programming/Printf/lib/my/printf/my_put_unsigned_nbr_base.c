/*
** EPITECH PROJECT, 2018
** my_put_unsigned_nbr_base.c
** File description:
** my_put_unsigned_nbr_base.c
*/

#include "../my.h"
#include "printf.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    int i = 1;

    while ((nb / i) >= 10)
        i = i * 10;
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i = i / 10;
    }
}

int my_put_unsigned_nbr_base(unsigned int nb, char *base)
{
    unsigned int res = 0;
    unsigned int save = 1;
    unsigned int size_base = my_strlen(base);

    while ((nb / save) >= size_base)
        save = save * size_base;
    while (save > 0) {
        res = (nb / save) % size_base;
        save = save / size_base;
        my_putchar(base[res]);
    }
}
