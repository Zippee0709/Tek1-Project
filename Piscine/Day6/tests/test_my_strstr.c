/*
** EPITECH PROJECT, 2018
** test_my_strstr.c
** File description:
** criterion test
*/

#include <criterion/criterion.h>

char    my_strstr(char *str, char const *to_find);

Test(my_strstr, string)
{
    char str[10] = "HelloWorld";
    char *to_find = "World";

    my_strstr(str, to_find);
    cr_assert_str_eq(str, to_find);
}
