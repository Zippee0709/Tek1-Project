/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** write a function that copies n character from a string into anoter, 
the destination string will already have enought memory to contain n characters
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n > i)
        dest[i] = '\0';
    return (dest);
}
