/*
** EPITECH PROJECT, 2019
** my_str_to_word_tab.c
** File description:
** my_str_to_word_tab.c
*/

#include "my.h"
#include "minishell.h"

int my_strlen_nb_word(char const *str, char c)
{
    int i = 0;
    int size = 0;
    
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == c || str[i + 1] == '\0' || str[i + 1] == '\n')
            size = size + 1;
        i = i + 1;
    }
    return (size);
}

int my_strlen_size_word(char const *str, int *i, char c)
{
    int size = 0;

    while (str[*i] != '\0' && str[*i] != c && str[*i] != '\n') {
        size = size + 1;
        *i = *i + 1;
    }
    return (size);
}

char **my_double_malloc(char const *str, int size, char c)
{
    int i = 0;
    int j = 0;
    int nb = 0;
    char **tab = malloc(sizeof(char *) * (size + 1));

    if (tab == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        exit(EXIT_ERROR);
    }
    while (i < size) {
        if (str[j] == c)
            j = j + 1;
        nb = my_strlen_size_word(str, &j, c);
        tab[i] = malloc(sizeof(char) * (nb + 1));
        i = i + 1;
    }
    tab[i] = NULL;
    return (tab);
}

char **my_fill_dtab(char const *str, char **tab, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == c) {
            tab[j][k] = '\0';
            i = i + 1;
            j = j + 1;
            k = 0;
        }
        tab[j][k] = str[i];
        k = k + 1;
        i = i + 1;
    }
    tab[j][k] = '\0';
    return (tab);
}

char **my_str_to_word_tab(char const *str, char c)
{
    int size = my_strlen_nb_word(str, c);
    char **tab = my_double_malloc(str, size, c);

    tab = my_fill_dtab(str, tab, c);
    return (tab);
}
