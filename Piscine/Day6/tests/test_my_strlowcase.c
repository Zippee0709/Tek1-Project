/*
** EPITECH PROJECT, 2018
** test_my_strcpy.c
** File description:
** criterion test
*/

#include <criterion/criterion.h>

char    *my_strlowcase(char *str);

Test(my_strupcase, change_all_char_in_maj)
{
    char str[6] = "HELLO";

    my_strlowcase(str);
    cr_assert_str_eq(str, "hello");
}
