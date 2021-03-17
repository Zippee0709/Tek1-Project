/*
** EPITECH PROJECT, 2019
** read_pos.c
** File description:
** read pos from file
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"

static const int FILE_SIZE = 31;
static const int MAJ_TO_NBR = 16;

int transform_letter_to_number(char **pos, int i)
{
    for (int j = 0; pos[i][j] != '\0'; j++)
        if (((pos[i][j] > 0 && pos[i][j] < '0') ||
            (pos[i][j] > '9' && pos[i][j] < 'A') ||
            (pos[i][j] > 'H')) && (pos[i][j] != ':'))
            return (-1);
        else if (pos[i][j] >= 'A' && pos[i][j] <= 'H')
            pos[i][j] -= MAJ_TO_NBR;
    return (0);
}

int check_pos_first_carac(char **pos)
{
    for (int i = 0; pos[i] != NULL; i++) {
        if (transform_letter_to_number(pos, i) == -1)
            return (-1);
    }
    return (0);
}

int get_pos_parse(char **pos, int actual_pos)
{
    char a = 0;
    char b = 0;
    char **parse = NULL;

    for (int i = 0; pos[i] != NULL; i++) {
        parse = my_parser(pos[i], ":");
        a = my_getnbr(parse[1]);
        b = my_getnbr(parse[2]);
        if (check_error(parse, actual_pos) == -1)
            return (-1);
        if (((b - a) != my_getnbr(parse[0]) - 1) &&
            ((b - a) != (my_getnbr(parse[0]) - 1) * 10)) {
            free_parse(parse);
            return (-1);
        }
        free_parse(parse);
    }
    return (0);
}

int check_pos_error(char **pos)
{
    int actual_pos = 0;

    if (my_check_nb_boat(pos) == -1)
        return (-1);
    if (check_pos_first_carac(pos) == -1)
        return (-1);
    if (get_pos_parse(pos, actual_pos) == -1)
        return (-1);
    return (0);
}

char **read_pos(char *pathfile)
{
    char **copy;
    char buffer[FILE_SIZE];
    int fd = open(pathfile, O_RDONLY);

    if (fd == -1)
        return (NULL);
    if (read(fd, buffer, FILE_SIZE) == -1)
        return (NULL);
    buffer[FILE_SIZE] = '\0';
    copy = my_parser(buffer, "\n");
    if (check_pos_error(copy) == -1) {
        my_putstr_fd(2, "Error syntax position.\n");
        free_parse(copy);
        return (NULL);
    }
    return (copy);
}
