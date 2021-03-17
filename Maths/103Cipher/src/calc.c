/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** all usefull calc function
*/

#include "cipher.h"

int my_get_matrix(int **key, int **msg, int i, int j)
{
    int x = 0;
    int z = 0;
    int nb = 0;

    while (msg[i][x] != '\0') {
        nb = nb + (msg[i][x] * key[z][j]);
        x = x + 1;
        z = z + 1;
    }
    return (nb);
}

int **my_calc_matrix(int **matrix, int **key, int **msg, int size)
{
    int i = 0;
    int j = 0;

    while (msg[i] != NULL) {
        while (j != size) {
            matrix[i][j] = my_get_matrix(key, msg, i, j);
            j = j + 1;
        }
        matrix[i][j] = '\0';
        j = 0;
        i = i + 1;
    }
    matrix[i] = NULL;
    return (matrix);
}
