/*
** EPITECH PROJECT, 2018
** cat.c
** File description:
** program witch execute the same task as system cat func
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"

int my_cat(char *file)
{
    char buffer[32];
    int size = 0;
    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        my_putstr_err("cat: ");
        my_putstr_err(file);
        my_putstr_err(": No such file or directory\n");
        return (84);
    }
    while ((size = read(fd, buffer, 31)) != 0)
        write(1, buffer, size);
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac < 2) {
        my_putstr_err("Error: Must specified file !\n");
        return (84);
    }
    while (i < ac) {
        if (my_cat(av[i]) == 84)
            return (84);
        i = i + 1;
    }
}
