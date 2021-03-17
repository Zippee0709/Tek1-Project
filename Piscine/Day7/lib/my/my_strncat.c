/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** idem my_strcat but with nb char
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int size = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[size] = src[i];
        size = size + 1;
        i = i + 1;
    }
    if (nb > i)
        dest[size] = '\0';
    return (dest);
}
