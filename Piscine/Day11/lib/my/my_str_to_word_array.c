/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** split string into word ans save them in double array
*/

#include "my.h"

int my_strlen_word(char const *str)
{
    int i = 0;
    int status = 0;
    int nb_word = 0;

    while (str[i] != '\0') {
        if (my_check_sign(str[i]) == 1)
            status = 0;
        else if (status == 0) {
            nb_word = nb_word + 1;
            status = 1;
        }
        i = i + 1;
    }
    return (nb_word);
}

int my_char_isprintable(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122) || c == 95)
        return (1);
    return (0);
}

char **my_array_malloc(char const *str, int size)
{
    int i = 0;
    int k = 0;
    int nb_c = 0;
    char **tab = malloc(sizeof(char *) * (size + 1));

    while (i != size) {
        while (my_check_sign(str[k]) == 1)
            k = k + 1;
        while (my_char_isprintable(str[k]) == 1) {
            nb_c = nb_c + 1;
            k = k + 1;
        }
        tab[i] = malloc(sizeof(char) * (nb_c + 1));
        nb_c = 0;
        i = i + 1;
    }
    return (tab);
}

char **my_array_fill(char const *str, int size, char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i != size) {
        while (my_check_sign(str[k]) == 1)
            k = k + 1;
        while (my_char_isprintable(str[k]) == 1) {
            tab[i][j] = str[k];
            j = j + 1;
            k = k + 1;
        }
        tab[i][j] = '\0';
        i = i + 1;
        j = 0;
    }
    tab[i] = NULL;
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    int size = my_strlen_word(str);
    char **tab = my_array_malloc(str, size);

    tab = my_array_fill(str, size, tab);
    return (tab);
}
