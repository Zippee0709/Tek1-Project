/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "dante.h"

int my_error_size(int x, int y)
{
    if (x <= 0 && y <= 0)
        return (84);
    return (0);
}

int my_error_type(Dante_t *dante, int ac, char **av)
{
    if (ac == 3 || (ac == 4 && my_strcmp(av[3], "imperfect") == 0))
        dante->type = IMPERFECT;
    else if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        dante->type = PERFECT;
    else {
        printf("Error : The last argument must be imperfect/perfect\n");
        return (84);
    }
    return (0);
}
