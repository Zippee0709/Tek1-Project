/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** all usefull function who check value
*/

#include "bistromatic.h"
#include "my.h"

static int check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr_err(SYNTHAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    return (EXIT_SUCCESS);
}

static int check_base(char const *base)
{
    if (my_strlen(base) < 2) {
        my_putstr_err(SYNTHAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    return (EXIT_SUCCESS);
}

int my_check_av(char **av)
{
    if (check_base(av[1]) == EXIT_BASE)
        exit(EXIT_BASE);
    else if (check_ops(av[2]) == EXIT_OPS)
        exit(EXIT_OPS);
    return (EXIT_SUCCESS);
}

int my_check_num(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}
