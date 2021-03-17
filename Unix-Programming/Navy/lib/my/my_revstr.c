/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char swap;

    while (j > i) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        j = j - 1;
        i = i + 1;
    }
    return (str);
}
