/*
** EPITECH PROJECT, 2018
** my_put_nbr_base.c
** File description:
** my_put_nbr_base.c
*/

#include "../my.h"
#include "printf.h"

char *my_put_nbr_base(int nb, char *base)
{
    int i = 0;
    int res = 0;
    int save = 1;
    int size_base = my_strlen(base);
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        my_putstr_err("Error : Malloc failed !\n");
    while ((nb / save) >= size_base)
        save = save * size_base;
    while (save > 0) {
        res = (nb /save) % size_base;
        save = save / size_base;
        str[i] = base[res];
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}

void my_put_nbr_base_s(int nb, char *base)
{
    int res = 0;
    int save = 1;
    int size_base = my_strlen(base);

    while ((nb / save) >= size_base)
        save = save * size_base;
    while (save > 0) {
        res = (nb /save) % size_base;
        save = save / size_base;
        my_putchar(base[res]);
    }
}
