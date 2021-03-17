/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bombyx.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_error_av1, check_good_return_of_av1)
{
    char *str = "3";
    int status = check_error_av1(str);

    cr_assert_eq(status, 0);
    cr_log_warn("Test check_error_av1 with 3 SUCCESS\n");
}

Test(check_error_av1, check_bad_return_of_av1)
{
    char *str = "a";
    int status = check_error_av1(str);

    cr_assert_eq(status, 84);
    cr_log_warn("Test check_error_av1 with 3 SUCCESS\n");
}

Test(my_is_num, check_bad_return_my_is_num)
{
    int status = my_is_num('a');

    cr_assert_eq(status, 84);
    cr_log_warn("Test my_is_num with letter SUCCESS\n");
}

Test(my_is_num, check_good_return_my_is_num)
{
    int status = my_is_num('1');

    cr_assert_eq(status, 1);
    cr_log_warn("Test my_is_num with letter SUCCESS\n");
}

/* Test(my_functionnal_bombyx, check_out_put_value, .init = redirect_all_std) */
/* { */
/*     char *str = "./106bombyx 10 3.3"; */
/*     char *ptr = "head data"; */

/*     system(str); */
/*     system(ptr); */
/* } */

Test(check_error_av1, check_false_return_of_av1, .init = redirect_all_std)
{
    char *str = "echo $?";
    int status = check_error_av1("a");

    cr_assert_stderr_eq_str("Error : Invalid argument 1\n");
    cr_log_warn("Test check_error_av1 with letter SUCCESS\n");
}
