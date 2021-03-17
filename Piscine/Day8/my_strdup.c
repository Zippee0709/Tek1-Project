/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** allocates memory and copies the string given as argument
*/

#include "include/my.h"

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *copy = malloc(sizeof(char) * size);

    my_strcpy(copy, src);
    return (copy);
}
