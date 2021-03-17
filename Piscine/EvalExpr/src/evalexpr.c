/*
** EPITECH PROJECT, 2018
** eval.c
** File description:
** eval.c
*/

#include "my.h"
#include "evalexpr.h"

int my_check_priority(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (1);
    else if (c == '+' || c == '-')
        return (2);
    return (0);
}

int my_calc_parenthesis(char **str)
{
    int nb = 0;

    printf("str calc = %s\n", *str);
    if (**str == '(') {
        *str = *str + 1;
        nb = my_eval_np(str);
        if (**str == ')')
            *str = *str + 1;
        printf("my calc nb = %d\n", nb);
        return (nb);
    }    
    printf("my cti = %d\n", my_cti_double(str));
    return (my_cti_double(str));
}

int my_eval_wp(char **str)
{
    printf("str with parenthese = %s\n", *str);
    int nb1 = my_calc_parenthesis(str);
    int nb2 = 0;
    char sign = '0';
    
    while (**str != '\0') {
        sign = **str;
        if (my_check_priority(**str) != 1)
            return (nb1);
        *str = *str + 1;
        nb2 = my_calc_parenthesis(str);
        if (sign == '*')
            nb1 = nb1 * nb2;
        else if (sign == '/')
            nb1 = nb1 / nb2;
        else
            nb1 = nb1 % nb2;
    }
    return (nb1);
}

int my_eval_np(char **str)
{
    printf("str no parenthese = %s\n", *str);
    int nb1 = my_eval_wp(str);
    int nb2 = 0;
    char sign = '0';

    while (**str != '\0') {
        sign = **str;
        if (my_check_priority(**str) != 2)
            return (nb1);
        *str = *str + 1;
        nb2 = my_eval_wp(str);
        if (sign == '+')
            nb1 = nb1 + nb2;
        else if (sign == '-')
            nb1 = nb1 - nb2;
    }
    return (nb1);
}

int eval_expr(char *str)
{
    int res = 0;
    if ((str = my_del_space(str)) == NULL)
        return (84);
    res = my_eval_np(&str);
    return (res);
}
