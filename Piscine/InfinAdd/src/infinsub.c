/*
** EPITECH PROJECT, 2018
** infinsub.c
** File description:
** infinsub
*/

#include "my.h"
#include "infinadd.h"

int my_sub_res(char s1, char s2, int i, int l)
{
    int res = 0;

    if (i < l)
        res = cti(s1) - cti(s2);
    else
        res = cti(s1);
    return (res);
}

int my_check_sup_ret(int retenu, int value)
{
    if (retenu == 1)
        value = value - retenu;
    return (value);
}

int my_check_sup_value(int value)
{
    if (value < 0)
        return (1);
    return (0);
}

char *my_put_in_res(char *res, int value, int i)
{
    if (value > 9) {
        res[i] = itc(value % 10);
        res[i + 1] = itc(value / 10);
    }
    else
        res[i] = itc(value);
    return (res);
}

void infinsub(char *s1, char *s2, infin_t *infin)
{
    int i = 0;
    int value = 0;
    int retenu = 0;
    
    while (s1[i] != '\0' && s1[i] != '-') {
        value = my_sub_res(s1[i], s2[i], i, my_check_size(s2));
        value = my_check_sup_ret(retenu, value);
        retenu = my_check_sup_value(value);
        if (value < 0)
            value = value + 10;
        infin->res = my_put_in_res(infin->res, value, i);
        i = i + 1;
    }
}
