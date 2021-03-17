/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull func
*/

#include "cipher.h"

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i = i + 1;
    }
}

int my_strlen(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

void my_print_key_matrix(int **matrix, int size, int height)
{
    int i = 0;
    int j = 0;

    printf("Key matrix:\n");
    while (i != height) {
        while (j != size) {
            printf("%d\t", matrix[i][j]);
            j = j + 1;
        }
        printf("\n");
        j = 0;
        i = i + 1;
    }
}

void my_print_encrypted_matrix(int **matrix, int size, int height)
{
    int i = 0;
    int j = 0;

    printf("Encrypted message:\n");
    while (i != height) {
        while (j != size) {
            printf("%d ", matrix[i][j]);
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    printf("\n");
}
