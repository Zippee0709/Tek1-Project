/*
** EPITECH PROJECT, 2018
** read;c
** File description:
** all usefull function who read file
*/

#include "my.h"
#include "sokoban.h"

int get_size_with_stat(char const *str)
{
    struct stat info;
    int size = 0;

    if (stat(str, &info) == -1) {
        my_putstr_err("Error : read stat failed\n");
        exit(84);
    }
    size = (int)info.st_size;
    return (size);
}

char *read_file(char const *str, int size)
{
    int fd = open(str, O_RDONLY);
    char *map = malloc(sizeof(char) * (size + 1));

    if (read(fd, map, size) < 0) {
        my_putstr_err("Error : read file failed\n");
        exit(84);
    }
    map[size] = '\0';
    close(fd);
    return (map);
}

void my_tab_copy(char **s1, char **s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != NULL) {
        while (s1[i][j] != '\0') {
            s2[i][j] = s1[i][j];
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
}
