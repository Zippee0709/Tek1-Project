/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** write a function that reverses a string.
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char    *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c;

    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    str[i + j + 1] = '\0';
    return (str);
}
