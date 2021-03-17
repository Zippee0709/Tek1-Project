/*
** EPITECH PROJECT, 2018
** infinsub.c
** File description:
** all usefull function for infinsub
*/

#include "bistromatic.h"
#include "my.h"

int my_sub_res(char nb1, char nb2, nb_s *calc, int i)
{
    int res = 0;

    if (i < calc->size_ns)
        res = cti(nb1) - cti(nb2);
    else
        res = cti(nb1);
    return (res);
}

char my_sub(char nb1, char nb2, nb_s *calc, int i)
{
    int res = my_sub_res(nb1, nb2, calc, i);

    if (calc->ret == 1) {
        res = res - calc->ret;
        calc->ret = 0;
    }
    if (res < 0) {
        res = res + 10;
        calc->ret = 1;
    }
    return (itc(res));
}

void infinsub(char *nb1, char *nb2, nb_s *calc)
{
    int i = 0;
    int j = 0;

    while (nb1[i] != '\0' && nb1[i] != '-') {
        calc->res[j] = my_sub(nb1[i], nb2[i], calc, i);
        i = i + 1;
        j = j + 1;
    }
    my_put_neg(calc, &j);
    calc->res[j] = '\0';
    my_revstr(calc->res);
    calc->res = my_delete_zero(calc->res);
}

void infinsub_gestion(char *nb1, char *nb2, nb_s *calc)
{
    if (who_is_bigger(nb1, nb2) == TRUE) {
        infinsub(nb2, nb1, calc);
        calc->neg = 1;
    }
    else
        infinsub(nb1, nb2, calc);
}

char *call_infinsub(char *nb1, char *nb2)
{
    nb_s calc;
    init_calc(&calc, nb1, nb2);
    my_revstr(nb1);
    my_revstr(nb2);

    if (calc.size1 == calc.size2)
        infinsub_gestion(nb1, nb2, &calc);
    else if (calc.size1 > calc.size2) {
        calc.size_ns = my_strlen_no_space(nb2);
        infinsub(nb1, nb2, &calc);
    }
    else {
        calc.neg = 1;
        calc.size_ns = my_strlen_no_space(nb1);
        infinsub(nb2, nb1, &calc);
    }
    return (calc.res);
}
