/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "bombyx.h"

void my_help(void)
{
    printf("USAGE\n\t./106bombyx n [k | i0 i1]\n\n");
    printf("DESCRIPTION\n\tn\tnumber of first");
    printf("generation individuals\n");
    printf("\tk\tgrowth rate from 1 to 4\n");
    printf("\ti0\tinitial generation (included)\n");
    printf("\ti1\tfinal generation (included)\n");
}

int main(int ac, char **av)
{
    global_t global;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help();
        return (0);
    }
    else if (check_error(ac, av) == 84)
        return (84);
    init_global(&global, ac, av);
    my_bombyx(&global, ac);
    return (0);
}
