/*
** EPITECH PROJECT, 2018
** infindiv.c
** File description:
** all usefull function who make infin_div
*/

#include "bistromatic.h"
#include "my.h"

char *infindiv(char *nb1, char *nb2)
{
    int i = 1;
    int k = 0;
    int result = (my_getnbr(nb1) / my_getnbr(nb2));
    char *res = malloc(sizeof(char) * my_strlen(nb1 + 2));

    if (result < 0) {
        res[k] = '-';
        k = k + 1;
    }
    while ((result / i) >= 10)
        i = i * 10;
    while (i > 0) {
        res[k] = itc((result / i) % 10);
        i = i / 10;
        k = k + 1;
    }
    res[k] = '\0';
    return (res);
}

char *infinmod(char *nb1, char *nb2)
{
    int i = 1;
    int k = 0;
    int result = (my_getnbr(nb1) % my_getnbr(nb2));
    char *res = malloc(sizeof(char) * my_strlen(nb1 + 2));

    if (result < 0) {
        res[k] = '-';
        k = k + 1;
    }
    while ((result / i) >= 10)
        i = i * 10;
    while (i > 0) {
        res[k] = itc((result / i) % 10);
        i = i / 10;
        k = k + 1;
    }
    res[k] = '\0';
    return (res);
}
