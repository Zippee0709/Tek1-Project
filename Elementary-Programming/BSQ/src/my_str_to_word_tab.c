/*
** EPITECH PROJECT, 2018
** my_str_to_array.c
** File description:
** my_str_to_array
*/

#include "my.h"
#include "bsq.h"

void my_del_first_lign(char *str, int *i)
{
    while (str[*i] != '\n')
        *i = *i + 1;
    *i = *i + 1;
}

int my_get_lenght(char *str)
{
    int i = 0;
    int lenght = 0;

    my_del_first_lign(str, &i);
    while (str[i] != '\0' && str[i] != '\n') {
        lenght = lenght + 1;
        i = i + 1;
    }
    return (lenght);
}

void my_check_char(bsq_s *bsq, char c, int *j, int *k)
{
    if (c == '.') {
        bsq->tab[*j][*k] = '.';
        *k = *k + 1;
    }
    else if (c == 'o') {
        bsq->tab[*j][*k] = 'o';
        *k = *k + 1;
    }
}

void my_check_backslash_n(bsq_s *bsq, char c, int *j, int *k)
{
    if (c == '\n') {
        bsq->tab[*j][*k] = '\0';
        *j = *j + 1;
        *k = 0;
    }
    else if (c != '\n' && c != '.' && c != 'o') {
        my_putstr_err(ERROR_CONTAIN_MSG);
        exit(EXIT_ERROR);
    }
}

void my_str_to_word_tab(bsq_s *bsq, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    my_del_first_lign(str, &i);
    while (str[i] != '\0') {
        my_check_char(bsq, str[i], &j, &k);
        my_check_backslash_n(bsq, str[i], &j, &k);
        i = i + 1;
    }
    if (str[i] == '\0' && str[i- 1] != '\n') {
        bsq->tab[j][k] = '\0';
        j = j + 1;
    }
    bsq->tab[j] = NULL;
}
