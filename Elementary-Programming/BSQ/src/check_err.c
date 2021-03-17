/*
** EPITECH PROJECT, 2018
** check_err.c
** File description:
** all usefull function who check str
*/

#include "my.h"
#include "bsq.h"

void my_check_lign_lenght(int nb, int lenght)
{
    if (nb != lenght) {
        my_putstr_err(ERROR_CONTAIN_MSG);
        exit(EXIT_ERROR);
    }
}

void my_check_bn(char c, int *nb_bn, int *nb, int lenght)
{
    if (c == '\n') {
        *nb_bn = *nb_bn + 1;
        my_check_lign_lenght(*nb, lenght);
        *nb = 0;
    }
}

void my_check_str_same_lenght(char *str, int *i)
{
    int nb = 0;
    int nb_bn = 0;
    int width = my_getnbr(str);
    int lenght = my_get_lenght(str) + 1;

    while (str[*i] != '\0') {
        nb = nb + 1;
        my_check_bn(str[*i], &nb_bn, &nb, lenght);
        *i = *i + 1;
    }
    if (str[*i] == '\0' && str[*i - 1] != '\n') {
        nb = nb + 1;
        my_check_lign_lenght(nb, lenght);
        nb_bn = nb_bn + 1;
    }
    my_check_lign_lenght(nb_bn, width);
}

void my_check_str(char *str)
{
    int i = 0;

    while (my_check_digit(str[i]) == 1)
        i = i + 1;
    if (str[i] == '\n') {
        i = i + 1;
        my_check_str_same_lenght(str, &i);
        return;
    }
    else {
        my_putstr_err(ERROR_CONTAIN_MSG);
        exit(EXIT_ERROR);
    }
}
