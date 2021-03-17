/*
** EPITECH PROJECT, 2018
** test_my_check_char.c
** File description:
** unit test
*/

#include <criterion/criterion.h>

int my_check_char(char c);

Test(my_check_char, check_good_return_of_char)
{
    char c = 'a';
    int res = 2;

    res = my_check_char(c);
    cr_assert_eq(res, 1);
}

Test(my_check_char, check_good_return_not_char)
{
    char c = ' ';
    int res = 2;

    res = my_check_char(c);
    cr_assert_eq(res, 0);
}
