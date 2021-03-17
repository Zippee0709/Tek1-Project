/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** all usefull function for init struct
*/

#include "bistromatic.h"
#include "my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr_err(SYNTHAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (size + 1));
    if (expr == 0) {
        my_putstr_err(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr_err(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

int init_bistro(bistro_s *bistro, char **av)
{
    bistro->size = my_getnbr(av[3]);
    bistro->expr = get_expr(bistro->size);
    bistro->operator = my_strdup(av[2]);
    bistro->parent = 0;
    return (EXIT_SUCCESS);
}

int init_calc(nb_s *calc, char *nb1, char *nb2)
{
    calc->size1 = my_strlen_no_space(nb1);
    calc->size2 = my_strlen_no_space(nb2);
    calc->neg = my_check_neg(nb1, nb2);
    calc->ret = 0;

    if (calc->size1 >= calc->size2)
        calc->res = malloc(sizeof(char) * (calc->size1 + 2));
    else
        calc->res = malloc(sizeof(char) * (calc->size2 + 2));
    return (EXIT_SUCCESS);
}

int init_calc_mul(nb_s *calc, char *nb1, char *nb2)
{
    calc->size1 = my_strlen_no_space(nb1);
    calc->size2 = my_strlen_no_space(nb2);
    calc->neg = my_check_neg(nb1, nb2);
    calc->ret = 0;
    calc->res = malloc(sizeof(char) * (calc->size1 + calc->size2 + 2));
    return (EXIT_SUCCESS);
}
