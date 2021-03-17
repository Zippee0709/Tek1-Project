/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull function
*/

#include "bistromatic.h"
#include "my.h"

char *my_nb_if_neg(char **str, char *nb, int *i)
{
    if (**str == '-') {
        nb[*i] = **str;
        *str = *str + 1;
        *i = *i + 1;
    }
    return (nb);
}

char *my_cti_str(char **str)
{
    int i = 0;
    char *nb = malloc(sizeof(char) * (1000));

    if (nb == NULL) {
        my_putstr_err(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    nb = my_nb_if_neg(str, nb, &i);
    while (**str >= '0' && **str <= '9') {
        nb[i] = **str;
        *str = *str + 1;
        i = i + 1;
    }
    nb[i] = '\0';
    return (nb);
}
