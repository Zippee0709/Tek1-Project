/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** all usefull function who check file
*/

#include "rush3.h"

int my_check_char_ifnot_good(char *str)
{
    if (str[0] != 'o' && str[0] != '*' && str[0] != 'A' && str[0] != 'B' && str[0] != '/') {
        my_putstr_err("File no found\n");
        return (84);
    }
    return (0);
}

int call_func(char *str, int x, int y, int i)
{
    if (x == 1 && y == 1) {
        if (only_one_line(str) == 84)
            return (84);
    }
    else if (multiple_line(str, x, y, i) == 84)
        return (84);
    return (0);
}
