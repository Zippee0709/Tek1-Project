/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "bombyx.h"

int check_error_av1(char *av)
{
    int i = 0;

    while (av[i] != '\0') {
        if (my_is_num(av[i]) == 84) {
            my_putstr_err("Error : Invalid argument 1\n");
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_error_av2(char *av)
{
    int i = 0;
    int nb = 0;

    while (av[i] != '\0') {
        if (av[i] == '.')
            nb = nb + 1;
        else if (my_is_num(av[i]) == 84 || nb > 1) {
            my_putstr_err("Error : Invalid argument 2\n");
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_error_basic(int ac, char **av)
{
    if (ac == 3) {
        if (check_error_av1(av[1]) == 84 ||
            check_error_av2(av[2]) == 84)
            return (84);
    }
    return (0);
}

int check_error_advance(int ac, char **av)
{
    if (ac == 4) {
        if (check_error_av1(av[1]) == 84 ||
            check_error_av1(av[2]) == 84 ||
            check_error_av1(av[3]) == 84)
            return (84);
    }
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac != 3 && ac != 4) {
        my_putstr_err("Error : Invalid argument\n");
        return (84);
    }
    else if (atof(av[1]) <= 0) {
        my_putstr_err("Error : The n value need to positive than 0.\n");
        return (84);
    }
    if (check_error_basic(ac, av) == 84 ||
        check_error_advance(ac, av) == 84)
        return (84);
    return (0);
}
