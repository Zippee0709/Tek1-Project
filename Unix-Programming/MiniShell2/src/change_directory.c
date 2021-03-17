/*
** EPITECH PROJECT, 2019
** change_directory.c
** File description:
** change_directory.c
*/

#include "my.h"
#include "minishell.h"

static int my_cd_home(Shell_t *shell, char *pwd, char *home, char *old)
{
    if (home == NULL || pwd == NULL || old == NULL || chdir(home) == -1)
        return (84);
    my_setenv(shell, "OLDPWD", old);
    my_setenv(shell, "PWD", pwd);
    return (1);
}

static int my_cd_ddot(Shell_t *shell, char *pwd, char *old)
{
    pwd = my_clean_path(pwd, '/');
    if (pwd == NULL || old == NULL || chdir(pwd) == -1)
        return (84);
    my_setenv(shell, "OLDPWD", old);
    my_setenv(shell, "PWD", pwd);
    return (1);
}

static int my_cd_minus(Shell_t *shell, char *pwd, char *old)
{
    pwd = my_get_env(shell->env, "OLDPWD=");
    if (pwd == NULL || old == NULL || chdir(pwd) == -1)
        return (84);
    my_setenv(shell, "OLDPWD", old);
    my_setenv(shell, "PWD", pwd);
    return (1);
}

static int my_cd_directory(Shell_t *shell, char *pwd, char *old, char *cmd)
{
    struct stat sb;

    if (stat(cmd, &sb) == -1) {
        my_put_error_access(cmd, ": No such file or directory.\n");
        return (84);
    }
    if (sb.st_mode == S_IFDIR ) {
        my_put_error_access(cmd, ": Permission denied.\n");
        return (84);
    }
    pwd = my_str_concat_c(pwd, cmd, "/");
    if (pwd == NULL || old == NULL || chdir(pwd) == -1) {
        my_put_error_access(cmd, ": Not a directory.\n");
        return (84);
    }
    my_setenv(shell, "OLDPWD", old);
    my_setenv(shell, "PWD", pwd);
    return (1);
}

int my_check_directory(Shell_t *shell, char **cmd)
{
    char *home = my_get_env(shell->env, "HOME=");
    char *pwd = my_get_env(shell->env, "PWD=");
    char *old = my_strdup(pwd);
    int status = 0;

    if (cmd[1] == NULL)
        status = my_cd_home(shell, pwd, home, old);
    else if (my_strcmp(cmd[1], "..") == 0)
        status =my_cd_ddot(shell, pwd, old);
    else if (my_strcmp(cmd[1], "-") == 0)
        status = my_cd_minus(shell, pwd, old);
    else
        status = my_cd_directory(shell, pwd, old, cmd[1]);
    free(pwd);
    free(home);
    free(old);
    return (status);
}
