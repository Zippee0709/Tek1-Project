/*
** EPITECH PROJECT, 2018
** infinadd.c
** File description:
** all usefull function to build infinity addition
*/

#include "bistromatic.h"
#include "my.h"

int my_add_res(char nb1, char nb2, nb_s *calc, int i)
{
    int res = 0;

    if (i < calc->size_ns)
        res = cti(nb1) + cti(nb2);
    else
        res = cti(nb1);
    return (res);
}

char my_add(char nb1, char nb2, nb_s *calc, int i)
{
    int res = my_add_res(nb1, nb2, calc, i);

    if (calc->ret == 1) {
        res = res + calc->ret;
        calc->ret = 0;
    }
    if (res >= 10) {
        res = res - 10;
        calc->ret = 1;
    }
    return (itc(res));
}

void infinadd(char *nb1, char *nb2, nb_s *calc)
{
    int i = 0;
    int j = 0;

    while (nb1[i] != '\0' && nb1[i] != '-') {
        calc->res[j] = my_add(nb1[i], nb2[i], calc, i);
        j = j + 1;
        i = i + 1;
    }
    my_check_ret(calc, &j);
    my_put_neg(calc, &j);
    calc->res[j] = '\0';
    calc->res = my_revstr(calc->res);
}

char *call_infinadd(char *nb1, char *nb2)
{
    nb_s calc;
    init_calc(&calc, nb1, nb2);
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);

    if (calc.size1 >= calc.size2) {
        calc.size_ns = my_strlen_no_space(nb2);
        infinadd(nb1, nb2, &calc);
    }
    else {
        calc.size_ns = my_strlen_no_space(nb1);
        infinadd(nb2, nb1, &calc);
    }
    return (calc.res);
}

char *my_infinadd_pos_neg(char *nb1, char *nb2)
{
    if (my_check_neg(nb1, nb2) == 1)
        return (call_infinadd(nb1, nb2));
    else if (my_check_neg(nb1, nb2) == 2)
        return (call_infinsub(nb1, nb2));
    else
        return (call_infinadd(nb1, nb2));
}
