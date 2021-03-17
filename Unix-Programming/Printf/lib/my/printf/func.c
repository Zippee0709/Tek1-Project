/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull func
*/

#include "../my.h"
#include "printf.h"

int my_get_nbdigit(int nb)
{
    int i = 0;
    int m = 1;

    while (nb / m > 0) {
        m = m * 10;
        i = i + 1;
    }
    return (i);
}
