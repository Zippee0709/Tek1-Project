/*
** EPITECH PROJECT, 2019
** get_file.c
** File description:
** get_file.c
*/

#include "minishell.h"

static int get_size_with_stat(char const *str)
{
    struct stat info;
    int size = 0;

    if (stat(str, &info) == -1)
        return (-1);
    size = (int)info.st_size;
    return (size);
}

char *get_file(char const *file)
{
    int size = get_size_with_stat(file);
    int fd = open(file, O_RDONLY);
    char *str = NULL;

    if (fd == -1 || size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    if (read(fd, str, size) == -1)
        return (NULL);
    str[size] = '\0';
    close(fd);
    return (str);
}
