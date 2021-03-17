/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** my main
*/
#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    tree(2);
    return (0);
}
