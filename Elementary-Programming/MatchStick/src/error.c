/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** all usefull function for check error
*/

#include "my.h"
#include "matchstick.h"

int my_line_error(int size)
{
    if (size < 1 || size > 100) {
        my_putstr_err("Error : The size is too low or too big !\n");
        return (-1);
    }
    return (0);
}

int my_stick_error(int stick, int size)
{
    if (size <= 0 || stick > size * 2 - 1) {
        my_putstr_err("Error : The stick is too low or too big !\n");
        return (-1);
    }
    return (0);
}

void print_line_err(void)
{
    my_putstr_err("Error : this line is out of range\n");
}

void print_stick_err(int max_value)
{
    my_putstr_err("Error : you cannot remove more than ");
    my_putnbr_err(max_value);
    my_putstr_err(" matches pers turn\n");
}
