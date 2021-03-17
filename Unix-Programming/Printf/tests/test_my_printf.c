/*
** EPITECH PROJECT, 2018
** test_my_printf.c
** File description:
** test_my_printf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(char *str, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, my_printf_no_flag, .init = redirect_all_std)
{
    my_printf("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_printf, my_printf_int_d, .init = redirect_all_std)
{
    int nb = 2123;
    my_printf("%d", nb);
    cr_assert_stdout_eq_str("2123");
}

Test(my_printf, my_printf_int_i, .init = redirect_all_std)
{
    int nb = 2123;
    my_printf("%i", nb);
    cr_assert_stdout_eq_str("2123");
}

Test(my_printf, my_printf_char, .init = redirect_all_std)
{
    char c = 'a';
    my_printf("%c", c);
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, my_printf_str, .init = redirect_all_std)
{
    char *str = "abcdef\n";
    my_printf("%s", str);
    cr_assert_stdout_eq_str("abcdef\n");
}

Test(my_printf, my_printf_binaire, .init = redirect_all_std)
{
    int nb = 21;
    my_printf("%b", nb);
    cr_assert_stdout_eq_str("10101");
}

Test(my_printf, my_printf_unsigned_int, .init = redirect_all_std)
{
    unsigned int nb = 123;
    my_printf("%u", nb);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, my_printf_octal, .init = redirect_all_std)
{
    int nb = 1997;
    my_printf("%o", nb);
    cr_assert_stdout_eq_str("3715");
}

Test(my_printf, my_printf_x, .init = redirect_all_std)
{
    int nb = 1997;
    my_printf("%x", nb);
    cr_assert_stdout_eq_str("7cd");
}

Test(my_printf, my_printf_X, .init = redirect_all_std)
{
    int nb = 1997;
    my_printf("%X", nb);
    cr_assert_stdout_eq_str("7CD");
}

Test(my_printf, my_printf_p, .init = redirect_all_std)
{
    int nb = 1997;
    my_printf("%p", nb);
    cr_assert_stdout_eq_str("0x7cd");
}

Test(my_printf, my_printf_s, .init = redirect_all_std)
{
    char str[5];

    strcpy(str, "toto");
    str[1] = 6;
    my_printf("%S", str);
    cr_assert_stdout_eq_str("t\006to");
}
