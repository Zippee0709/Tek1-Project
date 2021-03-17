/*
** EPITECH PROJECT, 2019
** free_parse.c
** File description:
** free_parser
*/

#include <stdlib.h>

int my_strlen(char const *str);

int check_each_separator_diff(char *str, char *separator, int i)
{
    int j = 0;
    int counter = 0;

    while (separator[j] != '\0') {
        if (str[i] != separator[j]) {
            counter++;
        }
        j++;
    }
    if (counter == my_strlen(separator))
        return (1);
    return (0);
}

void free_parse(char **parse)
{
    for (int i = 0; parse[i] != NULL; i++)
        free(parse[i]);
    free(parse);
}
