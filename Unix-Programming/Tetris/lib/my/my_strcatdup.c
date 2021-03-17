/*
** EPITECH PROJECT, 2019
** my_strcatdup.c
** File description:
** link two string in one & return it
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcatdup(char const *src, char *dest)
{
    int lensrc = my_strlen(src);
    int lendest = my_strlen(dest);
    int lentotal = lensrc + lendest;
    int i = 0;
    char *res = malloc(sizeof(char) * (lentotal + 1));

    for (int j = 0; src[j] != '\0'; j++, i++)
        res[i] = src[j];
    for (int k = 0; dest[k] != '\0'; k++, i++)
        res[i] = dest[k];
    res[lentotal] = '\0';
    return (res);
}
