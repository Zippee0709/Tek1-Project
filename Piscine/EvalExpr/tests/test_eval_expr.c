/*
** EPITECH PROJECT, 2018
** test_eval_expr.c
** File description:
** unit test for eval expr
*/

#include <criterion/criterion.h>

int eval_expr(char *str);

Test(eval_expr, test_one_one)
{
    char *str = "1+1";
    int res = 0;

    res = eval_expr(str);
    cr_assert_eq(res, 2);
}
