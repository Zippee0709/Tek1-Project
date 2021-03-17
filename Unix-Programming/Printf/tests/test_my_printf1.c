/*
** EPITECH PROJECT, 2018
** Test_printf1.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(char *str, ...);
void redirect_all_std(void);

Test(my_printf, my_printf_only_backslash_n, .init = redirect_all_std)
{
    my_printf("\n");
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, my_printf_many_type, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%d\n%s\n", 100, str);
    cr_assert_stdout_eq_str("100\nHello world\n");
}

Test(my_printf, my_printf_many_int, .init = redirect_all_std)
{
    my_printf("%d\n%d\n", 100, -123);
    cr_assert_stdout_eq_str("100\n-123\n");
}

Test(my_printf, my_printf_many_str, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%s\n%s\n", "Hello everyone", str);
    cr_assert_stdout_eq_str("Hello everyone\nHello world\n");
}

Test(my_printf, my_printf_no_match_flag, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%wWZA", str);
    cr_assert_stdout_eq_str("%wWZA");
}

Test(my_printf, my_printf_no_match_flag2, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%w%W%Z%A%%", str);
    cr_assert_stdout_eq_str("%w%W%Z%A%");
}

Test(my_printf, my_printf_only_modulo, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%%", str);
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, my_printf_only_modulo2, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%%%%%", str);
    cr_assert_stdout_eq_str("%%%");
}

Test(my_printf, my_printf_format_hashtag, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%#s", str);
    cr_assert_stdout_eq_str("Hello world");
}


Test(my_printf, my_printf_format_hashtag2, .init = redirect_all_std)
{
    char *str = "Hello world";

    my_printf("%#########s", str);
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_printf, my_printf_format_field, .init = redirect_all_std)
{
    char *str = "Hello";

    my_printf("%10s", str);
    cr_assert_stdout_eq_str("     Hello");
}

Test(my_printf, my_printf_format_field2, .init = redirect_all_std)
{
    char *str = "Hello";

    my_printf("%-10s", str);
    cr_assert_stdout_eq_str("Hello     ");
}

Test(my_printf, my_printf_format_field3, .init = redirect_all_std)
{
    char *str = "Hello";

    my_printf("%-+10s", str);
    cr_assert_stdout_eq_str("Hello     ");
}

Test(my_printf, my_printf_format_field_int, .init = redirect_all_std)
{
    int nb = 10;

    my_printf("%5d", nb);
    cr_assert_stdout_eq_str("   10");
}

Test(my_printf, my_printf_format_field_int2, .init = redirect_all_std)
{
    int nb = 10;

    my_printf("%-5d", nb);
    cr_assert_stdout_eq_str("10   ");
}

Test(my_printf, my_printf_format_field_int3, .init = redirect_all_std)
{
    int nb = 10;

    my_printf("%-+5d", nb);
    cr_assert_stdout_eq_str("  +10");
}
