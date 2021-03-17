/*
** EPITECH PROJECT, 2018
** read.c
** File description:
** all usefull function who read file given as parameter
*/

#include "my.h"
#include "bsq.h"

int get_file_size(char *file)
{
    int size = 1;
    char buffer[1];
    int fd = open(file, O_RDONLY);
    int lenght = 0;

    while ((size = read(fd, buffer, size)) != 0)
        lenght = lenght + size;
    close(fd);
    return (lenght);
}

char *my_malloc(int size)
{
    char *buffer = malloc(sizeof(char) * size + 1);

    if (buffer == NULL) {
        my_putstr_err(ERROR_MALLOC_MSG);
        exit(EXIT_ERROR);
    }
    return (buffer);
}

void my_double_malloc(bsq_s *bsq)
{
    int i = 0;
    bsq->tab = malloc(sizeof(char *) * (bsq->width + 1));

    if (bsq->tab == NULL) {
        my_putstr_err(ERROR_MALLOC_MSG);
        exit(EXIT_ERROR);
    }
    while (i <= bsq->width) {
        bsq->tab[i] = malloc(sizeof(char) * (bsq->lenght + 1));
        if (bsq->tab[i] == NULL) {
            my_putstr_err(ERROR_MALLOC_MSG);
            exit(EXIT_ERROR);
        }
        i = i + 1;
    }
}

char *read_file(char *file)
{
    int size = 0;
    char *buffer = NULL;
    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        my_putstr_err(ERROR_OPEN_MSG);
        exit(EXIT_ERROR);
    }
    size = get_file_size(file);
    buffer = my_malloc(size);
    if (read(fd, buffer, size) < 0) {
        my_putstr_err(ERROR_READ_MSG);
        exit(EXIT_FAILURE);
    }
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
