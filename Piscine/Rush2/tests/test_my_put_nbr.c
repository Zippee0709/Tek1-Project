/*
** EPITECH PROJECT, 2018
** test_my_put_nbr.c
** File description:
** unit test
*/

#include <criterion/criterion.h>

void my_put_nbr(int nb);

Test(my_put_nbr, check_good_print_number)
{
    int nb = 80;

    my_put_nbr(80);
    cr_assert_eq(stdout, 80);
}
