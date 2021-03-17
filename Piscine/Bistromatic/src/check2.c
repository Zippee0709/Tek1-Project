/*
** EPITECH PROJECT, 2018
** check2.c
** File description:
** all usefull check function
*/

#include "bistromatic.h"
#include "my.h"

int my_check_strnb_neg(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            return (TRUE);
        i = i + 1;
    }
    return (FALSE);
}

int my_parent_err(bistro_s *bistro)
{
    if (bistro->parent != 0) {
        my_putstr_err(SYNTHAX_ERROR_MSG);
        my_putchar_err('\n');
        exit (EXIT_USAGE);
    }
    return (EXIT_SUCCESS);
}

void my_check_parent(char a, char const *ops, bistro_s *bistro)
{
    if (a == ops[OP_OPEN_PARENT_IDX])
        bistro->parent = bistro->parent + 1;
    else if (a == ops[OP_CLOSE_PARENT_IDX])
        bistro->parent = bistro->parent - 1;
}

int my_check_same_ops(char const *ops, char a)
{
    int i = 2;

    while (ops[i] != '\0') {
        if (ops[i] == a) {
            my_putstr_err(SYNTHAX_ERROR_MSG);
            my_putchar_err('\n');
            exit (EXIT_USAGE);
        }
        i = i + 1;
    }
    return (EXIT_SUCCESS);
}

int my_check_ops(char const *str, char *ops, bistro_s *bistro)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ops[OP_OPEN_PARENT_IDX] ||
            str[i] == ops[OP_CLOSE_PARENT_IDX])
            my_check_parent(str[i], ops, bistro);
        else if (my_check_priority(str[i], ops) == TRUE ||
                 my_check_priority(str[i], ops) == 2)
            my_check_same_ops(ops, str[i + 1]);
        i = i + 1;
    }
    my_parent_err(bistro);
    return (EXIT_SUCCESS);
}
