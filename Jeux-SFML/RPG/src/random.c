/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** random.c
*/

#include "my_rpg.h"

static size_t get_seed(char const *s)
{
    size_t nb = 0;

    if (!s)
        return (FAILURE);
    for (int i = (s[0] == '-') ? 1 : 0; s[i] >= '0' && s[i] <= '9'; i++)
        nb = nb * 10 + s[i] - 48;
    return (s[0] == '-') ? (-nb) : (nb);
}

static int convert_into_str(size_t size, char **nb)
{
    int count = 1;

    if (*nb)
        free(*nb);
    for (size_t tmp = size; (tmp /= 10); count++);
    *nb = malloc(count + 1);
    if (!(*nb))
        return (FAILURE);
    (*nb)[count] = '\0';
    for (--count; size >= 10; count--) {
        (*nb)[count] = (size % 10) + 48;
        size /= 10;
    }
    (*nb)[count] = size + 48;
    return (SUCCESS);
}

static int write_new_nb(FILE *fd, char *nb, size_t size)
{
    fd = fopen(SEED, "w+");
    if (!fd)
        return (FAILURE);
    if (fwrite(nb, mstrlen(nb, 0), 1, fd) < 1)
        return (FAILURE);
    fclose(fd);
    free(nb);
    RES_X = 1366;
    RES_Y = 768;
    return (SUCCESS);
}

int new_seed(void)
{
    FILE *fd = fopen(SEED, "r+");
    char *nb = NULL;
    size_t size = 0;

    if (!fd)
        return (FAILURE);
    if (getline(&nb, &size, fd) == EOF)
        return (FAILURE);
    size = get_seed(nb);
    if (size == 0)
        return (FAILURE);
    srand(size++);
    if (convert_into_str(size, &nb) < 0)
        return (FAILURE);
    fclose(fd);
    return (write_new_nb(fd, nb, size));
}
