/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "trigo.h"

void my_check_type_tab(char *av, Global_t *global, char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strcmp(tab[i], av) == 0) {
            global->type = my_malloc_msg(av);
            return;
        }
        i++;
    }
    if (i >= 5) {
        my_putstr_err("Error : Fun doesn't match, please check help\n");
        my_free_dtab(global->tab_type);
        exit(EXIT_FAIL);
    }
}

int my_check_str_only_nbr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
            i++;
        else
            return (84);
    }
    return (0);
}

int my_check_value_av(int ac, char **av)
{
    int i = 2;

    while (i < ac) {
        if (my_check_str_only_nbr(av[i]) == 84)
            return (84);
        i++;
    }
    return (0);
}

void my_check_matrice_of_value(int ac)
{
    int i = 1;
    int square = 1;
    int size = ac - 2;

    while (square != size) {
        if (i > size) {
            my_putstr_err("Error : the number of ai must be a");
            my_putstr_err(" square of decimal number\n");
            exit(EXIT_FAIL);
        }
        i = i + 1;
        square = i * i;
    }
}

void my_check_error(Global_t *global, int ac, char **av)
{
    if (ac < 3) {
        my_putstr_err("Error : invalid argument\n");
        exit(EXIT_FAIL);
    }
    my_check_value_av(ac, av);
    my_check_matrice_of_value(ac);
    global->tab_type = my_malloc_dtab_type();
    my_check_type_tab(av[1], global, global->tab_type);
}
