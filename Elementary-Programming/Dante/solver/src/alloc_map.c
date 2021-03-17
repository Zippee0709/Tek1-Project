/*
** EPITECH PROJECT, 2019
** alloc_map
** File description:
** alloc
*/

#include "dante.h"

char *my_size(char *av)
{
    struct stat size_file;
    char *buffer = NULL;
    int fd = 0;

    if (stat(av, &size_file) == -1)
        exit(84);
    buffer = malloc(sizeof(char) * (size_file.st_size));
    fd = open(av, O_RDONLY);
    if (fd == -1) {
        free(buffer);
        exit(84);
    }
    read(fd, buffer, size_file.st_size);
    buffer[size_file.st_size - 1] = '\0';
    return (buffer);
}

int nb_lane(char *buffer)
{
    int y = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            y++;
    return (y);
}

char **filled_map(char **map, char *buf)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (; buf[i] != '\0'; i++, x++) {
        if (buf[i] == '\n') {
            map[y][x] = '\0';
            y++;
            i++;
            x = 0;
        }
        map[y][x] = buf[i];
    }
    map[y][x] = '\0';
    map[y + 1] = NULL;
    return (map);
}

char **alloc_map(char *av, s_map *map)
{
    map->buf = my_size(av);
    int lane = nb_lane(map->buf);
    int j = 0;
    int k = 0;

    map->map = malloc(sizeof(char *) * (lane + 2));
    for (int i = 0; i != lane + 1; i++) {
        for (;map->buf[j] != '\n' && map->buf[j] != '\0'; j++, k++);
        map->map[i] = malloc(sizeof(char) * (k + 1));
        map->map[i][k] = '\0';
        k = 0;
        j++;
    }
    filled_map(map->map, map->buf);
    free(map->buf);
    return (map->map);
}
