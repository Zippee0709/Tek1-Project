/*
** EPITECH PROJECT, 2018
** test_my_cipher.c
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include "../include/cipher.h"

Test(my_matrix_size, check_good_return_for_init_size1)
{
    char *str = "Homer S";
    int result = my_matrix_size(str);

    cr_assert_eq(result, 3);
}

Test(my_matrix_size, check_good_return_for_init_size2)
{
    char *str = "Home";
    int result = my_matrix_size(str);

    cr_assert_eq(result, 2);
}

Test(my_msg_convert, check_good_value_inside_key_matrix)
{
    char *str = "Homer S";
    int size = my_matrix_size(str);
    int **matrix = my_msg_convert(str, size);

    cr_assert_eq(matrix[0][0], 72);
    cr_assert_eq(matrix[0][1], 111);
    cr_assert_eq(matrix[0][2], 109);
    cr_assert_eq(matrix[1][0], 101);
    cr_assert_eq(matrix[1][1], 114);
    cr_assert_eq(matrix[1][2], 32);
    cr_assert_eq(matrix[2][0], 83);
    cr_assert_eq(matrix[2][1], 0);
    cr_assert_eq(matrix[2][2], 0);
}

Test(my_msg_convert, check_good_value_inside_msg_matrix)
{
    char *str = "Just beca";
    int size = my_matrix_size(str);
    int **matrix = my_msg_convert(str, size);

    cr_assert_eq(matrix[0][0], 74);
    cr_assert_eq(matrix[0][1], 117);
    cr_assert_eq(matrix[0][2], 115);

    cr_assert_eq(matrix[1][0], 116);
    cr_assert_eq(matrix[1][1], 32);
    cr_assert_eq(matrix[1][2], 98);

    cr_assert_eq(matrix[2][0], 101);
    cr_assert_eq(matrix[2][1], 99);
    cr_assert_eq(matrix[2][2], 97);
}
