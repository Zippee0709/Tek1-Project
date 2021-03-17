/*
** EPITECH PROJECT, 2019
** execution.c
** File description:
** execution func
*/

#include "my.h"
#include "minishell.h"

static int check_segfault(pid_t pid, int wstatus)
{
    int segfault = WTERMSIG(wstatus);

    if (segfault == SIGSEGV)
        my_putstr("Segmentation fault");
    if (segfault == SIGFPE)
        my_putstr("Floating exception");
    if (WCOREDUMP(wstatus)) {
        kill(pid, SIGSEGV);
        my_putstr(" (core dumped)\n");
    }
    else if (segfault != 0)
        my_putstr("\n");
    return (wstatus);
}

void my_exec(Shell_t *shell, char *full_path, char **cmd)
{
    int status = 0;
    redirect_t redir = {0, 0, NULL, NULL, NULL};
    pid_t pid = fork();

    if (pid == 0) {
        redir.pid = pid;
        cmd = do_redirect(cmd, &redir);
        execve(full_path, cmd, shell->env_tab);
        exit(0);
    }
    else {
        waitpid(pid, &status, WIFSIGNALED(status));
        status = check_segfault(pid, status);
    }
}

static int exec_binairies(Shell_t *shell, char **cmd)
{
    char *pwd = my_get_env(shell->env, "PWD=");
    shell->full_path = my_str_concat_c(pwd, cmd[0], "/");

    if (access(shell->full_path, F_OK) == -1 ||
        access(shell->full_path, X_OK) == -1) {
        free(shell->full_path);
        free(pwd);
        my_put_error_access(cmd[0], ": Command not found.\n");
        return (84);
    }
    my_exec(shell, shell->full_path, cmd);
    free(shell->full_path);
    free(pwd);
    return (0);
}

static int access_to_path(Shell_t *shell, char **cmd)
{
    if (access(shell->full_path, F_OK) == -1 ||
        access(shell->full_path, X_OK) == -1) {
        return (84);
    }
    shell->env_tab = copy_list_in_double_tab(shell->env);
    my_exec(shell, shell->full_path, cmd);
    free(shell->full_path);
    my_free_dtab(shell->env_tab);
    my_free_dtab(shell->path);
    return (0);
}

int check_access(Shell_t *shell, char **cmd)
{
    char *path = my_get_env(shell->env, "PATH=");

    if (path == NULL) {
        my_put_error_access(cmd[0], ": Command not found.\n");
        return (84);
    }
    shell->path = my_str_to_word_tab(path, ':');
    for (int i = 0; shell->path != NULL && shell->path[i] != NULL; i++) {
        shell->full_path = my_str_concat_c(shell->path[i], cmd[0], "/");
        if (access_to_path(shell, cmd) == 0) {
            free(path);
            return (0);
        }
        free(shell->full_path);
    }
    free(path);
    my_free_dtab(shell->path);
    return (exec_binairies(shell, cmd));
}
