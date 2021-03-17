/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get.c
*/

#include "trigo.h"

void display_float_tab(float *tab, int size)
{
    int y = 0;
    int x = 0;

    while (y < size) {
        while (x < size) {
            printf("%.2f", tab[x + (y * size)]);
            if (x != size - 1)
                printf("\t");
            else
                printf("\n");
            x++;
        }
        x = 0;
        y++;
    }
}

float *fill_basic_info(int size, int length)
{
    int x = 0;
    int y = 0;
    int sum = 0;
    float *tab = malloc(sizeof(float) * (length + 1));

    while (y < size) {
        while (x < size) {
            sum = x + (y * size);
            if (x == y)
                tab[sum] = 1;
            else
                tab[sum] = 0;
            x++;
        }
        x = 0;
        y++;
    }
    return (tab);
}

int empty_mat(float *tab, int length)
{
    int i = 0;

    while (i != length) {
        if (tab[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

int equal_mat(float *dest, float *src, int length)
{
    int i = 0;

    while (i < length) {
        if (dest[i] != src[i])
            return (0);
        i++;
    }
    return (1);
}

void copy_mat(float *dest, float *src, int length)
{
    memcpy(dest, src, sizeof(float) * length);
}
