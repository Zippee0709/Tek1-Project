/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for rush3
*/

#include <unistd.h>
#include "rush3.h"

int only_one_line(char *str)
{
    if (my_check_char_if_b(str) == 1)
        return (0);
    if (str[0] == 'o')
        my_putstr("[rush1-1] 1 1\n");
    else if (str[0] == '*')
        my_putstr("[rush1-2] 1 1\n");
    else {
        my_putstr_err("Not found file\n");
        return (84);
    }
    return (0);
}

int multiple_line(char *str, int x, int y, int i)
{
    my_check_rush1(str, x, y);
    my_check_rush2(str, x, y);
    my_check_rush3(str, x, y);
    my_check_rush4(str, x, y, i);
    my_check_rush5(str, x, y, i);
    if (my_check_char_ifnot_good(str) == 84)
        return (84);
    return (0);
}

void my_print(int x, int y)
{
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
}

int rush3(char *str)
{
    int i = 0;
    int x = 0;
    int y = 0;
    
    while (str[i] != '\n') {
        x = x + 1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n')
            y = y + 1;
        i = i + 1;
    }
    if (call_func(str, x, y, i) == 84)
        return (84);
    return (0);
}

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = 0;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    if (rush3(buff) == 84)
        return (84);
    return (0);
}
