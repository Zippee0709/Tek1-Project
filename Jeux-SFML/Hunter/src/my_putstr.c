/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** all usefull function for print
*/

#include "my_hunter.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_print_score(hunter_s *hunter)
{
    char *score = my_int_convert_str(hunter->score);
    my_putstr("You score is : ");
    my_putstr(score);
    my_putchar('\n');
}
