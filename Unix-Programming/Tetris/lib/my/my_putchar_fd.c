/*
** EPITECH PROJECT, 2018
** my_putchar_fd.c
** File description:
** my_putchar_fd
*/

#include <unistd.h>

int my_putchar_fd(int fd, char const c)
{
    write(fd, &c, 1);
    return (0);
}
