/*
** EPITECH PROJECT, 2019
** redirect.c
** File description:
** redirect.c
*/

#include "minishell.h"

void redirect_left(redirect_t *redir)
{
    int fd = 0;

    if (access(redir->array[0], F_OK) == -1) {
        my_put_error_access(redir->array[0], ": Permission denied.\n");
        exit(84);
    }
    fd = open(redir->array[0], O_RDWR);
    if (fd == -1) {
        my_put_error_access(redir->array[0], ": No such file or directory.\n");
        exit(84);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

void double_redirect_left(redirect_t *red)
{
    char *cmd = NULL;
    int status = 0;
    int fd = 0;

    while (status == 0) {
        my_putstr("> ");
        cmd = get_next_line(0);
        if (cmd == NULL)
            return;
        if (my_strncmp(cmd, red->array[0], my_strlen(red->array[0])) == 0)
            break;
        red->cmd = push_back_dlist(red->cmd, cmd);
    }
    free(cmd);
    dup2(fd, STDIN_FILENO);
    print_list(red->cmd);
    free_list(red->cmd);
    close(fd);
}

void redirect_right(redirect_t *redir)
{
    int fd = open(redir->array[0], O_RDWR | O_CREAT | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IWGRP | S_IWOTH);
    if (fd == -1) {
        my_put_error_access(redir->array[0], ": No such file or directory.\n");
        exit(84);
    }
    dup2(fd, STDOUT_FILENO);
    if (redir->type == DREDIRECT_RIGHT && redir->file != NULL)
        write(fd, redir->file, my_strlen(redir->file));
    close(fd);
}

char **do_redirect(char **cmd, redirect_t *redir)
{
    redir->type = check_redirect_tab(cmd);
    if (redir->type == NO_REDIRECT)
        return (cmd);
    cmd = delete_redirect(cmd, redir);
    redir->file = get_file(redir->array[0]);
    if (redir->type == DREDIRECT_RIGHT ||
        redir->type == REDIRECT_RIGHT)
        redirect_right(redir);
    else {
        if (redir->type == REDIRECT_LEFT)
            redirect_left(redir);
        if (redir->type == DREDIRECT_LEFT)
            double_redirect_left(redir);
        if (redir->pid == 0)
            exit(0);
    }
    return (cmd);
}
