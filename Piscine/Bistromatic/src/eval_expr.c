/*
** EPITECH PROJECT, 2018
** eval_expr.c
** File description:
** all usefull for eval_expr
*/

#include "bistromatic.h"
#include "my.h"

int my_check_priority(char c, char *ops)
{
    if (c == ops[OP_MUL_IDX] || c == ops[OP_DIV_IDX] || c == ops[OP_MOD_IDX])
        return (1);
    else if (c == ops[OP_PLUS_IDX] || c == ops[OP_SUB_IDX])
        return (2);
    return (0);
}

char *my_calc_parenthesis(char **str, char *ops)
{
    char *nb = 0;

    if (**str == ops[OP_OPEN_PARENT_IDX]) {
        *str = *str + 1;
        nb = my_eval_np(str, ops);
        if (**str == ops[OP_CLOSE_PARENT_IDX])
            *str = *str + 1;
        return (nb);
    }
    return (my_cti_str(str));
}

char *my_eval_wp(char **str, char *ops)
{
    char *nb1 = my_calc_parenthesis(str, ops);
    char *nb2 = 0;
    char sign = '0';

    while (**str != '\0') {
        sign = **str;
        if (my_check_priority(**str, ops) != TRUE)
            return (nb1);
        *str = *str + 1;
        nb2 = my_calc_parenthesis(str, ops);
        if (sign == ops[OP_MUL_IDX])
            nb1 = call_infinmul(nb1, nb2);
        else if (sign == ops[OP_DIV_IDX])
            nb1 = infindiv(nb1, nb2);
        else
            nb1 = infinmod(nb1, nb2);
    }
    return (nb1);
}

char *my_eval_np(char **str, char *ops)
{
    char *nb1 = my_eval_wp(str, ops);
    char *nb2 = 0;
    char sign = '0';

    while (**str != '\0') {
        sign = **str;
        if (my_check_priority(**str, ops) != 2)
            return (nb1);
        *str = *str + 1;
        nb2 = my_eval_wp(str, ops);
        if (sign == ops[OP_PLUS_IDX])
            nb1 = my_infinadd_pos_neg(nb1, nb2);
        else if (sign == ops[OP_SUB_IDX])
            nb1 = call_infinsub(nb1, nb2);
    }
    return (nb1);
}

char *eval_expr(bistro_s *bistro)
{
    char *res = NULL;

    my_check_ops(bistro->expr, bistro->operator, bistro);
    res = my_eval_np(&bistro->expr, bistro->operator);
    my_putstr(res);
    my_putchar('\n');
    return (res);
}
