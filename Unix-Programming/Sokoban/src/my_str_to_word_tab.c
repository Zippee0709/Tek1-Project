/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab.c
** File description:
** my_str_to_word_tab.c
*/

#include "my.h"
#include "sokoban.h"

int my_get_lenght(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i = i + 1;
    return (i);
}

int my_get_height(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}

char **my_double_malloc(char const *str)
{
    int i = 0;
    int height = my_get_height(str);
    int lenght = my_get_lenght(str);
    char **tab = malloc(sizeof(char *) * (height + 1));

    if (tab == NULL) {
        my_putstr_err("Error : Memory allocation failed\n");
        exit(EXIT_ERROR);
    }
    while (i != height) {
        tab[i] = malloc(sizeof(char) * (lenght + 1));
        if (tab[i] == NULL) {
            my_putstr_err("Error : Memory allocation failed\n");
            exit(EXIT_ERROR);
        }
        i = i + 1;
    }
    return (tab);
}

char my_stock_char(char c, int *j, int *k)
{
    if (c == '#' || c == ' ' || c == 'O' || c == 'P' || c == 'X') {
        *k = *k + 1;
        return (c);
    }
    else if (c == '\n') {
        *j = *j + 1;
        *k = 0;
        return ('\0');
    }
    else {
        my_putstr_err("Error : map contain unauthorised character\n");
        exit(EXIT_ERROR);
    }
}

char **my_str_to_word_tab(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = my_double_malloc(str);

    while (str[i] != '\0') {
        tab[j][k] = my_stock_char(str[i], &j, &k);
        i = i + 1;
    }
    tab[j] = NULL;
    return (tab);
}
