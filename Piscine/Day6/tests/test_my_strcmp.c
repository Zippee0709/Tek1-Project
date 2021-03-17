/*
** EPITECH PROJECT, 2018
** test_my_strcmp
** File description:
** criterion test
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, Compare_two_string_same_contains)
{
    char *str = "Hello";
    char *ptr = "Hello";
    int res = 0;

    res = my_strcmp(str, ptr);
    cr_assert_eq(res, 0);
}

Test(my_strcmp, Compare_two_string_first_more_long)
{
    char *str = "Hellooo";
    char *ptr = "Hello";
    int res = 0;

    res = my_strcmp(str, ptr);
    cr_assert_eq(res, -1);
}

Test(my_strcmp, Compare_two_string_second_more_long)
{
    char *str = "Hello";
    char *ptr = "Hellooo";
    int res = 0;

    res = my_strcmp(str, ptr);
    cr_assert_eq(res, 1);
}
