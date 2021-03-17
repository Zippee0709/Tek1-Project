/*
** EPITECH PROJECT, 2018
** infinmul.c
** File description:
** all usefull function who build infinmul
*/

#include "bistromatic.h"
#include "my.h"

void my_mul_ret(nb_s *calc, int *k)
{
    if (calc->ret > 0) {
        calc->res[*k] = itc(calc->ret);
        *k = *k + 1;
        calc->ret = 0;
    }
}

char my_mul(char nb1, char nb2, nb_s *calc, int k)
{
    int res = cti(nb1) * cti(nb2);

    if (my_check_num(calc->res[k]) == TRUE)
        res = res + cti(calc->res[k]);
    if (calc->ret > 0) {
        res = res + calc->ret;
        calc->ret = 0;
    }
    if (res >= 10) {
        calc->ret = res / 10;
        res = res % 10;
    }
    return (itc(res));
}

void infinmul(char *nb1, char *nb2, nb_s *calc)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (nb1[i] != '\0' && nb1[i] != '-') {
        while (nb2[j] != '\0' && nb2[j] != '-') {
            calc->res[k] = my_mul(nb1[i], nb2[j], calc, k);
            k = k + 1;
            j = j + 1;
        }
        my_mul_ret(calc, &k);
        j = 0;
        i = i + 1;
        k = i;
    }
    k = k + i;
    my_put_neg_mul(calc);
}

char *call_infinmul(char *nb1, char *nb2)
{
    nb_s calc;
    init_calc_mul(&calc, nb1, nb2);
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);

    if (calc.size1 >= calc.size2) {
        calc.size_ns = my_strlen_no_space(nb2);
        infinmul(nb1, nb2, &calc);
    }
    else {
        calc.size_ns = my_strlen_no_space(nb1);
        infinmul(nb2, nb1, &calc);
    }
    calc.res = my_revstr(calc.res);
    return (calc.res);
}
