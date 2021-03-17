/*
** EPITECH PROJECT, 2019
** test
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"
#include <sys/types.h>
#include <dirent.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strspecialcpy, test_cat_function, .init = redirect_all_std)
{
    char *ls = "ls";
    char *path = "PATH=/usr/local/sbin:/usr/local/bin:" \
        "/usr/sbin:/usr/bin:/home/Mwaaaa/my_scripts";
    int start = 0;

    my_printf("%s", strcpy_after(ls, path, &start));
    cr_assert_stdout_eq_str("/usr/local/sbin/ls");
}

Test(quit, verify_exit, .init = redirect_all_std)
{
    quit("exit");
    cr_assert_stdout_eq_str("exit\n");
}

Test(check_segfault, no_segfault, .init = redirect_all_std)
{
    pid_t child = 12321;
    int status = 0;

    cr_assert_eq(check_segfault(status, child), 0);
}

Test(check_access, file_not_a_dir_1, .init = redirect_all_std)
{
    char **command = NULL;

    command = malloc(sizeof(char *) * 2);
    command[0] = malloc(sizeof(char) * 3);
    command[0] = my_strcpy(command[0], "cd");
    command[1] = malloc(sizeof(char) * 9);
    command[1] = my_strcpy(command[1], "Makefile");
    check_access(command);
    free(command[1]);
    free(command[0]);
    free(command);
    cr_assert_stdout_eq_str("Makefile: Not a directory.\n");
}
