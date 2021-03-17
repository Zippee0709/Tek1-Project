/*
** EPITECH PROJECT, 2018
** func.c
** File description:
** all usefull function
*/

#include "my.h"
#include "evalexpr.h"

char *my_del_space(char *str)
{
    int i = 0;
    int j = 0;
    char *copy = malloc(sizeof(char) * my_strlen(str) + 1);

    if (copy == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        return (NULL);
    }
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            copy[j] = str[i];
            j = j + 1;
        }
        i = i + 1;
    }
    copy[j] = '\0';
    return (copy);   
}

int my_cti_double(char **str)
{
    int nb = 0;

    while (**str >= '0' && **str <= '9') {
        nb = nb * 10 + (**str - '0');
        *str = *str + 1;
    }
    return (nb);
}
