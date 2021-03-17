/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map.c
*/

#include "my_defender.h"

char *create_map_from_txt(char const *str)
{
    int fd = open(str, O_RDONLY);
    char *map = malloc(sizeof(char) * 451);

    if (map == NULL) {
        my_putstr_err("Error : Memory allocation failed\n");
        return (NULL);
    }
    if (read(fd, map, 450) < 0) {
        my_putstr_err("Error :  read file failed\n");
        return (NULL);
    }
    map[450] = '\0';
    close(fd);
    return (map);
}

static char **my_double_malloc(char const *str)
{
    int height = my_get_height(str);
    int lenght = my_get_lenght(str);
    char **map = malloc(sizeof(char *) * (height + 1));

    if (map == NULL) {
        my_putstr_err("Error : Memory allocation failed\n");
        return (NULL);
    }
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (lenght + 1));
        if (map[i] == NULL) {
            my_putstr_err("Error : Memory allocation failed\n");
            return (NULL);
        }
    }
    return (map);
}

char **my_str_to_word_tab(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **map = my_double_malloc(str);

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            map[j][k] = '\0';
            j++;
            k = 0;
        } else {
            map[j][k] = str[i];
            k++;
        }
        i++;
    }
    map[j] = NULL;
    return (map);
}
