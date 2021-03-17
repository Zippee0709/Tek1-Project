/*
** EPITECH PROJECT, 2019
** my_str_concat.c
** File description:
** my_str_concat func
*/

#include "my.h"
#include "minishell.h"

char *my_str_concat(char *s1, char *s2)
{
    int i = my_strlen(s1);
    int j = my_strlen(s2);
    char *str = malloc(sizeof(char) * (i + j + 2));

    if (str == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        exit(EXIT_FAILURE);
    }
    str[0] = '\0';
    my_strcat(str, s1);
    my_strcat(str, "/");
    my_strcat(str, s2);
    return (str);
}
