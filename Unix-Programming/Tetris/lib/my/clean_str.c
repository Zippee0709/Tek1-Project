/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** remove extra spaces
*/

#include <stdlib.h>

int my_strlen(char *str);

char *clean_str(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        if (str[i] != ' ' ||
            (str[i] == ' ' && str[i + 1] != ' ' &&
            str[i + 1] != '\0' && j != 0)){
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    free(str);
    new_str[j] = '\0';
    return (new_str);
}
