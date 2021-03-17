/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** str copy
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    int counter = 0;
    char *dest = malloc((sizeof(char) * my_strlen(str)) + 1);

    if (dest == NULL)
        return (NULL);
    while (str[counter] != '\0') {
        dest[counter] = str[counter];
        counter++;
    }
    dest[counter] = '\0';
    return (dest);
}
