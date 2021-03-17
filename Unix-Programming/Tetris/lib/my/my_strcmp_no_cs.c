/*
** EPITECH PROJECT, 2019
** my_strcmp_no_cs.c
** File description:
** compare two string without case sensitive
*/

#include <stdlib.h>

char *my_strdup(char const *str);

char *my_upcase(char *str)
{
    char *cpy = my_strdup(str);

    for (int i = 0; cpy[i] != '\0'; i++) {
        if (cpy[i] >= 'A' && cpy[i] <= 'Z')
            cpy[i] += 32;
    }
    return cpy;
}

int my_strcmp_no_cs(char *str, char *str2)
{
    int counter = 0;
    int i = 0;
    char *str_upcase = my_upcase(str);
    char *str2_upcase = my_upcase(str2);

    while (str_upcase[counter] != '\0' || str2_upcase[counter] != '\0') {
        if (str_upcase[counter] > str2_upcase[counter]) {
            free(str_upcase);
            free(str2_upcase);
            return (1);
        } else if (str_upcase[counter] < str2_upcase[counter]) {
            free(str_upcase);
            free(str2_upcase);
            return (-1);
        }
        counter++;
    }
    free(str_upcase);
    free(str2_upcase);
    return (0);
}
