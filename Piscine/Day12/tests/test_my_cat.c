/*
** EPITECH PROJECT, 2018
** test_my_cat.c
** File description:
** unit_test for cat
*/

#include <criterion/criterion.h>

int my_cat(char *file);

Test(my_cat, Test_my_cat_error_no_file)
{
    char *str = "nofile";
    int res = 0;

    res = my_cat(str);
    cr_assert_eq(res, 84);
}

Test(my_cat, Test_my_cat_with_exist_file)
{
    char *str = "../cat/cat.c";
    int res = 2;

    res = my_cat(str);
    cr_assert_eq(res, 0);
}
