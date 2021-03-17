/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull function
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while ((nb / i) >= 10)
        i = i * 10;
    while (i > 0) {
        my_putchar((nb / i) % 10 + 48);
        i = i / 10;
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

