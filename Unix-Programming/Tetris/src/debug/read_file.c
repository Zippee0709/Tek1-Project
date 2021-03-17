/*
** EPITECH PROJECT, 2019
** check_tetrimino
** File description:
** check tetrimino
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

int stock_tetrimino_forms(char *line, tetrimino_caract_t *caract,
                            int i, int counter)
{
    if (caract->forms == NULL)
        return (-1);
    if (count_occur(line, '*') > caract->size_x) {
        caract->correct = false;
        return (0);
    }
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
        if (line[i] != '*' && line[i] != ' ') {
            caract->correct = false;
            return (-2);
        }
    }
    caract->forms[i - 1] = my_strdup(line);
    if (counter > caract->size_y)
        caract->correct = false;
    return 0;
}

int check_first_line(char *line, tetrimino_caract_t *caract)
{
    char **tetrimino_info;
    int j = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if ((line[i] <= '0' || line[i] >= '9') && line[i] != ' '
            && line[i] != '\n') {
            caract->correct = false;
            return -2;
        }
    }
    tetrimino_info = my_parser(line, " ");
    for (; tetrimino_info[j] != NULL; j++);
    if (j != 3)
        return -1;
    caract->size_x = my_getnbr(tetrimino_info[0]);
    caract->size_y = my_getnbr(tetrimino_info[1]);
    caract->color = my_getnbr(tetrimino_info[2]);
    free_parse(tetrimino_info);
    return (0);
}

void free_read_file(char *line, FILE *stream)
{
    free(line);
    fclose(stream);
}

int read_first_line(char *line, tetrimino_caract_t *caract)
{
    if (check_first_line(line, caract) == -1)
        return -1;
    if ((caract->forms = malloc(sizeof(char *) * (caract->size_y + 1)))
        == NULL)
        return -1;
    return (0);
}

int read_file(char *filepath, tetrimino_caract_t *caract)
{
    FILE *stream = fopen(filepath, "r");
    char *line = NULL;
    size_t size;
    static int counter = 0;

    if (stream == NULL) {
        my_putstr_fd(2, "Error, can't read the file\n");
        return -1;
    }
    for (int i = 0; getline(&line, &size, stream) != -1; i++, counter++) {
        if (i == 0) {
            if (read_first_line(line, caract) == -1)
                return (-1);
        } else
            stock_tetrimino_forms(line, caract, i, counter);
    }
    caract->forms[caract->size_y] = NULL;
    free_read_file(line, stream);
    counter = 0;
    return 0;
}
