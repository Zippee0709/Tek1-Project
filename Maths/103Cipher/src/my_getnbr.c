/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** function that return a number sent to the function as a string.
*/

#include "cipher.h"

int check_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int check_sign(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if ((str[i] == '-' ) && (check_number(str[i + 1]) == 1))
            j = 1;
        i = i + 1;
    }
    return (j);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (check_number(str[i]) == 0)
            i = i + 1;
        else if (check_number(str[i]) == 1) {
            nb = nb * 10;
            nb = nb + (str[i] - '0');
            i = i + 1;
            if (check_number(str[i]) == 0 ) {
                if (check_sign(str) == 1)
                    nb = nb * (-1);
                return (nb);
            }
        }
    }
    return (nb);
}

int my_get_nbr_str(char const *str, int *i)
{
    int nb = 0;

    while (str[*i] >= '0' && str[*i] <= '9') {
        nb = nb + (str[*i] - '0');
        *i = *i + 1;
    }
    if (str[*i] == ' ')
        *i = *i + 1;
    return (nb);
}

int **my_get_all_nbr(char const *str, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int **matrix = my_malloc_msg_matrix(str, size);

    while (str[i] != '\0') {
        while (k != size) {
            matrix[j][k] = my_get_nbr_str(str, &i);
            k = k + 1;
        }
        matrix[j][k] = '\0';
        k = 0;
        j = j + 1;
    }
    matrix[j] = NULL;
    return (matrix);
}
