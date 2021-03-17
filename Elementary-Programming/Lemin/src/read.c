/*
** EPITECH PROJECT, 2019
**  read.c
** File description:
** read.c
*/

#include "lemin.h"
#include "my.h"

char *my_malloc_str(int size, char *buffer)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return (NULL);
    for (i = 0; buffer[i] != '\0'; i++)
        str[i] = buffer[i];
    str[i] = '\0';
    return (str);
}

char *read_file_with_getline(int fd)
{
    char buffer[4096];
    int size = 0;
    char *str = NULL;

    if ((size = read(fd, buffer, 4096)) == -1)
        return (NULL);
    buffer[size] = '\0';
    str = my_malloc_str(size, buffer);
    return (str);
}
