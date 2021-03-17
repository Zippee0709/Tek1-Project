/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** load_maps.c
*/

#include "my_rpg.h"

static int count_maps(void)
{
    int count = 0;
    DIR *folder = opendir("./config/.map");
    struct dirent *file = NULL;

    if (!folder)
        return (0);
    do {
        file = readdir(folder);
        if (file && file->d_name[0] == '.' && file->d_name[1] != '.' &&
            file->d_type == DT_REG)
            count++;
    } while (file);
    return (count);
}

tileset_t **load_maps(void)
{
    char *buf = NULL;
    int index = 0;
    DIR *folder = opendir("./config/.map/");
    tileset_t **map = malloc(sizeof(*map) * (count_maps() + 1));

    if (!count_maps() || !folder || !map)
        return (NULL);
    for (struct dirent *f = readdir(folder); f; f = readdir(folder))
        if (f->d_name[0] == '.' && f->d_name[1] ^ '.' && f->d_type == DT_REG) {
            buf = str_cat("./config/.map/", f->d_name);
            if (!buf)
                return (NULL);
            map[index] = gen(buf, open_file(buf));
            if (!map[index++])
                return (NULL);
        }
    map[index] = NULL;
    return (map);
}
