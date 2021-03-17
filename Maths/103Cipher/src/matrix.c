/*
** EPITECH PROJECT, 2018
** matrix.c
** File description:
** all usefull function matrix
*/

#include "cipher.h"

int my_matrix_size(char const *str)
{
    int size = my_strlen(str);
    int nb = 0;

    if (size > 9)
        exit(84);
    if (size >= 5)
        nb = 3;
    else if (size <= 4 && size >= 3)
        nb = 2;
    else
        nb = 1;
    return (nb);
}

int my_get_height(char const *str, int size_m)
{
    int size = my_strlen(str);
    int nb = size / size_m;

    if (size % size_m > 0)
        nb = nb + 1;
    return (nb);
}

int **my_malloc_msg_matrix(char const *str, int size_m)
{
    int i = 0;
    int size = my_get_height(str, size_m);
    int **matrix = malloc(sizeof(int *) * (size + 1));

    if (matrix == NULL) {
        my_putstr_err("Error : Allocation failed\n");
        exit(84);
    }
    while (i != size) {
	matrix[i] = malloc(sizeof(int) * (size_m + 1));
	if (matrix[i] == NULL) {
            my_putstr_err("Error : Allocation failed\n");
            exit(84);
	}
        i = i + 1;
    }
    return (matrix);
}

int **my_msg_convert(char const *str, int size_m)
{
    int i = 0;
    int j = 0;
    int	k = 0;
    int	**matrix = my_malloc_msg_matrix(str, size_m);

    while (str[i] != '\0') {
        while (k != size_m) {
            if (str[i] == '\0')
                matrix[j][k] = (int)str[i];
            else {
                matrix[j][k] = (int)str[i];
                i = i + 1;
            }
            k = k + 1;
        }
        matrix[j][k] = '\0';
	k = 0;
	j = j + 1;
    }
    matrix[j] = NULL;
    return (matrix);
}

void my_free_matrix(int **matrix)
{
    int i = 0;
    
    while (matrix[i] != NULL) {
        free(matrix[i]);
        i = i + 1;
    }
    free(matrix);
}
