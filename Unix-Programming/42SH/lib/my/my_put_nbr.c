/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display nb param
*/

#include "my.h"

int neg(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    return (nb);
}

int divi(int nb)
{
    int pow = 1;
    while (nb >= 100) {
        nb = nb / 10;
        pow = pow * 10;
    }
    return (pow);
}

int first(int nb)
{
    while (nb >= 10) {
        nb = nb / 10;
    }
    return (nb);
}

int count_digit(int nb)
{
    int dig = 0;
    while (nb > 0) {
        nb = nb / 10;
        dig++;
    }
    return (dig);
}

int my_put_nbr(int nb)
{
    int modulo;
    int nbcpy;

    nb = neg(nb);
    if (nb > 9) {
        nbcpy = nb;
        my_putchar(first(nb) + 48);
        modulo = divi(nb);
        while (modulo > 0) {
            nb = nb / modulo;
            nb = nb % 10;
            my_putchar(nb + 48);
            modulo = modulo / 10;
            nb = nbcpy;
        }
    } else
        my_putchar(nb + 48);
    return 0;
}
