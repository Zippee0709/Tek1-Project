/*
** EPITECH PROJECT, 2018
** test_my_strcmp
** File description:
** criterion test
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, Compare_two_string_same_contains)
{
    char *str = "AbCde";
    char *ptr = "AbCde";
    int res = 0;

    res = my_strncmp(str, ptr, 3);
    cr_assert_eq(res, 0);
}

Test(my_strncmp, Compare_two_string_first_more_long)
{
    char *str = "ABCDE";
    char *ptr = "abcd";
    int res = 0;

    res = my_strncmp(str, ptr, 3);
    cr_assert_eq(res, -1);
}

Test(my_strncmp, Compare_two_string_second_more_long)
{
    char *str = "abcd";
    char *ptr = "abDEF";
    int res = 0;

    res = my_strncmp(str, ptr, 3);
    cr_assert_eq(res, 1);
}
