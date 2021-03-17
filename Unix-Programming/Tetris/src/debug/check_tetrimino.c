/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Tetris' bootstrap main
*/

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

const int NAME_EXTRA = 10;

int recup_name(tetrimino_caract_t *caract, char *filename)
{
    int i = 0;

    if (my_strstr(filename, ".tetrimino\0$") == -1) {
        return (-2);
    }
    caract->name =
        malloc(sizeof(char) * (my_strlen(filename) - NAME_EXTRA + 1));
    if (caract->name == NULL)
        return (-1);
    for (; filename[i] != '.'; i++)
        caract->name[i] = filename[i];
    caract->name[i] = '\0';
    return 0;
}

int check_tetrimino(char *filepath, char *filename, tetrimino_caract_t *caract)
{
    if (caract == NULL) {
        my_putstr_fd(2, "Error malloc\n");
        return -1;
    }
    caract->correct = true;
    if (recup_name(caract, filename) == -1)
        return -2;
    if (read_file(filepath, caract) == -1) {
        return -1;
    }
    return 0;
}
