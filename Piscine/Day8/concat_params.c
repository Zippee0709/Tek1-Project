/*
** EPITECH PROJECT, 2018
** concat_params
** File description:
** turns commande line given into a signle string, argument separe by \n
*/

#include "include/my.h"

int my_strlen_params(char **av)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while (av[i] != NULL) {
        while (av[i][j] != '\0') {
            len = len + 1;
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (len);
}

char *concat_params(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int size = my_strlen_params(av);
    char *copy = malloc(sizeof(char) * size);

    while (av[i] != NULL) {
        while (av[i][j] != '\0') {
            copy[k] = av[i][j];
            j = j + 1;
            k = k + 1;
        }
        copy[k] = '\n';
        k = k + 1;
        i = i + 1;
        j = 0;
    }
    return (copy);
}
