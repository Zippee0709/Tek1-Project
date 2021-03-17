/*
** EPITECH PROJECT, 2018
** do_op.c
** File description:
** do_op.c
*/

#include "my.h"

void my_add(int nb1, int nb2);
void my_sous(int nb1, int nb2);
void my_mul(int nb1, int nb2);
void my_div(int nb1, int nb2);
void my_mod(int nb1, int nb2);

void my_get_sign(char *str, int nb1, int nb2)
{
    int i = 0;
    int k = 0;
    char *sign = "+-*/%";
    void (*tab_func[5])(int,int) = {my_add, my_sous, my_mul, my_div, my_mod};

    while (str[k] != '\0') {
        while (sign[i] != '\0') {
            if (str[k] == sign[i]) {
                (*tab_func[i])(nb1, nb2);
            }
            i = i + 1;
        }
        k = k + 1;
    }
}

int my_check_av(int ac, char **av)
{
    if (ac > 4 || ac < 4)
        return (1);
    else if (my_getnbr(av[1]) == 0 || my_getnbr(av[3]) == 0)
        return (1);
    return (0);
}

int do_op(char *s1, char *sign, char *s2)
{
    int nb1 = my_getnbr(s1);
    int nb2 = my_getnbr(s2);
    
    if (nb1 == 0 && nb2 == 0)
        my_putstr("0\n");
    else
        my_get_sign(sign, nb1, nb2);
    return (0);
}
