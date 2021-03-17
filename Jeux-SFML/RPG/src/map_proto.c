/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map_gen2.c
*/

#include "my_rpg.h"

int count_lines(char *buf)
{
    int nb = 0;
    int index = 0;

    if (!buf)
        return (-1);
    while (buf[index])
        nb += (buf[index++] == '\n') ? 1 : 0;
    if (buf[index - 1] ^ '\n')
        nb += 1;
    free(buf);
    return (nb);
}

char **create_proto(char const *file, FILE *fd)
{
    size_t n = 0;
    int index = -1;
    int lines = count_lines(read_file(file)) - 1;
    char **map = malloc(sizeof(char *) * (lines + 1));

    if (!map || !fd || lines < 1)
        return (NULL);
    for (int a = 0; a ^ (lines + 1); a++)
        map[a] = NULL;
    do {
        n = getline(&map[++index], &n, fd);
        if (n < 0)
            return (NULL);
    } while (index ^ (lines - 1));
    fclose(fd);
    return (map);
}
