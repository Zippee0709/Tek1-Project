 /*
** EPITECH PROJECT, 2018
** my_put_func.C
** File description:
** all usefull put function
*/

#include "my.h"
#include "infinadd.h"

void my_put_retenu(infin_t *infin, int *j, int *retenu)
{
    if (*retenu == 1) {
        infin->res[*j] = itc(*retenu);
        *j = *j + 1;
    }
}

void my_put_neg(infin_t *infin, int *j)
{
    if (infin->neg == 1 || infin->neg == 2) {
        infin->res[*j] = '-';
        *j = *j + 1;
    }
}

char *my_put_sup_neg(char *res)
{
    int i = my_strlen(res);

    res[i] = '-';
    res[i + 1] = '\0';
    return (res);
}

int my_who_is_neg(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            return (1);
        i = i + 1;
    }
    return (0);
}

int my_check_size(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            j = j + 1;
        i = i + 1;
    }
    i = i - j;
    return (i);
}
