/*
** EPITECH PROJECT, 2019
** test_function.c
** File description:
** unit_test for function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

int get_number_from_letter(char letter);
int my_get_number(char letter);
void fill_map_null(char map[MAP_MAX][MAP_MAX]);

Test(get_number_from_letter, test_return_of_letter)
{
    int nb = get_number_from_letter('A');
    cr_assert_eq(nb, 0);
    cr_log_warn("test return of letter 'A' SUCCESS\n");

    nb = get_number_from_letter('B');
    cr_assert_eq(nb, 1);
    cr_log_warn("test return of letter 'B' SUCCESS\n");

    nb = get_number_from_letter('C');
    cr_assert_eq(nb, 2);
    cr_log_warn("test return of letter 'C' SUCCESS\n");

    nb = get_number_from_letter('D');
    cr_assert_eq(nb, 3);
    cr_log_warn("test return of letter 'D' SUCCESS\n");

    nb = get_number_from_letter('E');
    cr_assert_eq(nb, 4);
    cr_log_warn("test return of letter 'E' SUCCESS\n");

    nb = get_number_from_letter('F');
    cr_assert_eq(nb, 5);
    cr_log_warn("test return of letter 'F' SUCCESS\n");

    nb = get_number_from_letter('G');
    cr_assert_eq(nb, 6);
    cr_log_warn("test return of letter 'G' SUCCESS\n");

    nb = get_number_from_letter('H');
    cr_assert_eq(nb, 7);
    cr_log_warn("test return of letter 'H' SUCCESS\n");

    nb = get_number_from_letter('Z');
    cr_assert_eq(nb, -1);
    cr_log_warn("test return of invalid letter SUCCESS\n");
}

Test(my_get_number, test_return_of_function)
{
    int nb = my_get_number('A');
    cr_assert_eq(nb, 0);
    cr_log_warn("test return of function 'A' SUCCESS\n");

    nb = my_get_number('1');
    cr_assert_eq(nb, 1);
    cr_log_warn("test return of number '1' SUCCESS\n");

    nb = my_get_number('2');
    cr_assert_eq(nb, 2);
    cr_log_warn("test return of number '2' SUCCESS\n");

    nb = my_get_number('3');
    cr_assert_eq(nb, 3);
    cr_log_warn("test return of number '3' SUCCESS\n");

    nb = my_get_number('4');
    cr_assert_eq(nb, 4);
    cr_log_warn("test return of number '4' SUCCESS\n");

    nb = my_get_number('5');
    cr_assert_eq(nb, 5);
    cr_log_warn("test return of number '5' SUCCESS\n");

    nb = my_get_number('6');
    cr_assert_eq(nb, 6);
    cr_log_warn("test return of number '6' SUCCESS\n");

    nb = my_get_number('7');
    cr_assert_eq(nb, 7);
    cr_log_warn("test return of number '7' SUCCESS\n");

    nb = my_get_number('8');
    cr_assert_eq(nb, 8);
    cr_log_warn("test return of number '8' SUCCESS\n");
}

/* Test(fill_map_null, test_map_if_filled_correcly) */
/* { */
/*     int i = 0; */
/*     char map[MAP_MAX][MAP_MAX]; */
/*     char *str = "......."; */

/*     fill_map_null(map); */
/*     while (i != MAP_MAX) { */
/*         printf("map[%d] = %s", i, map[i]); */
/*         cr_assert_str_eq(str, map[i]); */
/*         i = i + 1; */
/*     } */
/*     cr_log_warn("test if map filled correcly with only .\n"); */
/* } */
