/*
** EPITECH PROJECT, 2019
** math.c
** File description:
** math.c
*/

#include "trigo.h"

float *div_mat(float *src, float k, int length, int size)
{
    float *mat = malloc(sizeof(float) * length);
    int y = 0;
    int x = 0;

    while (y < size) {
        while (x < size) {
            mat[x + (y * size)] = src[x + (y * size)] / k;
            x++;
        }
        x = 0;
        y++;
    }
    return (mat);
}

float *multi_mat(float *src, float *obj, int length, int size)
{
    float *mat = malloc(sizeof(float) * length);
    float tmp = 0;
    int y = 0;
    int x = 0;
    int i = 0;

    while (y < size) {
        while (x < size) {
            tmp = 0;
            while (i < size) {
                tmp += src[(y * size) + i] * obj[(i * size) + x];
                i++;
            }
            mat[x + (y * size)] = tmp;
            i = 0;
            x++;
        }
        x = 0;
        y++;
    }
    return (mat);
}

float *add_mat(float *src, float *obj, int length)
{
    int i = 0;
    float *mat = malloc(sizeof(float) * length);
    
    if (mat == NULL)
        return (NULL);
    while (i < length) {
        mat[i] = src[i] + obj[i];
        i++;
    }
    return (mat);
}

float *sub_mat(float *src, float *obj, int length)
{
    int i = 0;
    float *mat = malloc(sizeof(float) * length);

    if (mat == NULL)
        return (NULL);
    while (i < length) {
        mat[i] = src[i] - obj[i];
        i++;
    }
    return (mat);
}
