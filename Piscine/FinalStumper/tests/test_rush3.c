/*
** EPITECH PROJECT, 2018
** test_rush3.c
** File description:
** unit test for rush3
*/

#include <criterion/criterion.h>

int rush3(char *str);

Test(rush3, test_good_input)
{
    char *str = "o";
    int res = -1;

    res = rush3(str);
    cr_assert_eq(0, res);
}

Test(rush3, test_bad_input)
{
    char *str = "H";
    int res = -1;

    res = rush3(str);
    cr_assert_eq(0, res);    
}
