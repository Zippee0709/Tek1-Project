/*
** EPITECH PROJECT, 2019
** error management
** File description:
** minishell
*/

#include "my.h"

void toomuch_arg(char **arr)
{
    my_putstr(arr[0]);
    my_putstr(": Too much arguments.\n");
}

void notenough_arg(char *arr)
{
    my_putstr(arr);
    my_putstr(": Not enough arguments.\n");
}
