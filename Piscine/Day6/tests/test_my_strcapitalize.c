/*
** EPITECH PROJECT, 2018
** test_my_strcpy.c
** File description:
** criterion test
*/

#include <criterion/criterion.h>

char    *my_strcapitalize(char *str);

Test(my_strcapitalize, change_all_char_in_maj)
{
    char str[12] = "how are you?";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "How Are You?");
}
