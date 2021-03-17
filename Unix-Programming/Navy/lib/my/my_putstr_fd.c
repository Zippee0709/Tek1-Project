/*
** EPITECH PROJECT, 2018
** my_putstr_fd.c
** File description:
** my_putstr opti + chosse fd
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr_fd(int fd, char const *str)
{
    int size = my_strlen(str);

    write(fd, str, size);
    return (0);
}
