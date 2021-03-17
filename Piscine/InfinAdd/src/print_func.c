/*
** EPITECH PROJECT, 2018
** print_func.c
** File description:
** all usefull print_func
*/

#include "my.h"
#include "infinadd.h"

int my_if_print_sub(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i = i + 1;
    while (str[i] != '\0') {
        if (str[i] != '0')
            return (1);
        i = i + 1;
    }
    return (0);
}

void my_print_sup_res(char *str)
{
    int i = 0;

    if (my_if_print_sub(str) == 1 && str[i] == '-') {
        my_putchar(str[i]);
        i = i + 1;
    }
    else if (my_if_print_sub(str) == 0) {
        my_putstr("0\n");
        return;
    }
    while (str[i] == '0')
        i = i + 1;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    my_putchar('\n');
}
