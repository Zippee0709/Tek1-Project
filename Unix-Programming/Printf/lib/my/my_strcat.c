/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** write a function that concatenates two string.
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_size = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_size] = src[i];
        i = i + 1;
        dest_size = dest_size + 1;
    }
    dest[dest_size] = '\0';
    return (dest);
}
