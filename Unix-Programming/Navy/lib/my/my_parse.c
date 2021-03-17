/*
** EPITECH PROJECT, 2019
** my_parse.c
** File description:
** parser, return an char ** from char *
*/

#include <stdlib.h>

int my_strlen(char const *str);

int check_each_separator_diff(char *str, char *separator, int i);

int check_each_separator_equal(char *str, char *separator, int i)
{
    int j = 0;
    int counter = 0;

    while (separator[j] != '\0') {
        if (str[i] == separator[j]) {
            counter++;
        }
        j++;
    }
    if (counter > 0)
        return (1);
    return (0);
}

int count_argv(char *str, char *separator)
{
    int counter_space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((check_each_separator_diff(str, separator, i)) &&
            (check_each_separator_equal(str, separator, i + 1) ||
            str[i + 1] == '\0'))
            counter_space++;
    }
    return (counter_space);
}

int malloc_parse(char **parse, char *str, char *separator, int nbr_argv)
{
    int counter_line = 0;
    int caract_nbr = 0;

    for (int i = 0; i < nbr_argv; i++) {
        while (check_each_separator_equal(str, separator, counter_line))
            counter_line++;
        while (check_each_separator_diff(str, separator, counter_line) &&
                str[counter_line] != '\0') {
            counter_line++;
            caract_nbr++;
        }
        if ((parse[i] = malloc(sizeof(char) * (caract_nbr + 1))) == NULL)
            return (-1);
        counter_line++;
        caract_nbr = 0;
    }
    return (0);
}

void fill_parse(char **parse, char *str, char *separator, int nbr_argv)
{
    int counter_line = 0;
    int caract_nbr = 0;

    for (int i = 0; i < nbr_argv; i++) {
        while (check_each_separator_equal(str, separator, counter_line))
            counter_line++;
        while (check_each_separator_diff(str, separator, counter_line) &&
                str[counter_line] != '\0') {
            parse[i][caract_nbr] = str[counter_line];
            counter_line++;
            caract_nbr++;
        }
        parse[i][caract_nbr] = '\0';
        counter_line++;
        caract_nbr = 0;
    }
    parse[nbr_argv] = NULL;
}

char **my_parser(char *str, char *separator)
{
    char **parse;
    int nbr_argv = 0;

    if (str == NULL)
        return (NULL);
    nbr_argv = count_argv(str, separator);
    if ((parse = malloc(sizeof(char *) * (nbr_argv + 1))) == NULL)
        return (NULL);
    if (malloc_parse(parse, str, separator, nbr_argv) == -1)
        return (NULL);
    fill_parse(parse, str, separator, nbr_argv);
    return (parse);
}
