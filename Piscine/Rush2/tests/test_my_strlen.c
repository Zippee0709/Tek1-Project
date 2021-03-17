/*
** EPITECH PROJECT, 2018
** test_my_strlen.c
** File description:
** unit test
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

Test(my_strlen, count_number_char)
{
    char *str = "Hello";
    int res = 0;

    res = my_strlen(str);
    cr_assert_eq(res, 5);
}
