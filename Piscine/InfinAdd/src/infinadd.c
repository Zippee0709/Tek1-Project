/*
** EPITECH PROJECT, 2018
** infinadd.c
** File description:
** infinadd.c
*/

#include "my.h"
#include "infinadd.h"

int init_infin(infin_t *infin, char **av)
{
    infin->neg = 0;
    if (my_check_negative(av[1], av[2]) == 1)
        infin->neg = 1;
    else if (my_check_negative(av[1], av[2]) == 2)
        infin->neg = 2;
    infin->s1 = my_revstr(av[1]);
    infin->s2 = my_revstr(av[2]);
    infin->size1 = my_strlen(av[1]);
    infin->size2 = my_strlen(av[2]);
    infin->res = malloc(sizeof(char) * (infin->size1 + infin->size2 + 3));

    if (infin->res == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        return (84);
    }
    my_call_func(infin);
    return (0);
}

int my_add_res(char s1, char s2, int i, int l)
{
    int res;

    if (i < l)
        res = cti(s1) + cti(s2);
    else
        res = cti(s1);
    return (res);
}

char my_add(char s1, char s2, int *retenu, int i, int l)
{
    int res = my_add_res(s1, s2, i, l);

    if ((*retenu) == 1) {
        res = res + *retenu;
        *retenu = 0;
    }
    if (res >= 10) {
        res = res - 10;
        *retenu = 1;
    }
    return (itc(res));
}

void my_check_lenght(infin_t *infin)
{
    if (infin->size1 >= infin->size2)
        infinadd(infin->s1, infin->s2, infin);
    else
        infinadd(infin->s2, infin->s1, infin);
}

void infinadd(char *s1, char *s2, infin_t *infin)
{
    int i = 0;
    int j = 0;
    int retenu = 0;

    while (s1[i] != '\0' && s1[i] != '-') {
        infin->res[j] = my_add(s1[i], s2[i], &retenu, i, my_check_size(s2));
        j = j + 1;
        i = i + 1;
    }
    my_put_retenu(infin, &j, &retenu);
    my_put_neg(infin, &j);
    infin->res[j] = '\0';
    infin->res = my_revstr(infin->res);
    my_putstr(infin->res);
    my_putchar('\n');
}
