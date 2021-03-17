/*
** EPITECH PROJECT, 2019
** redirect.c
** File description:
** redirect.c
*/

#include "../include/minishell.h"

int redirect_right(redirect_s *redirect)
{
    int fd = open(redirect->array[0], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
                    S_IRGRP | S_IWGRP | S_IWUSR);

    if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
        return (84);
    if (redirect->type == DREDIRECT_RIGHT && redirect->file != NULL)
        write(fd, redirect->file, strlen(redirect->file));
    close(fd);
    return (0);
}

int redirect_left(redirect_s *red)
{
    int fd = open(red->array[0], O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "%s: No such file or directory.\n", red->array[0]);
        return (84);
    }
    write(0, red->file, strlen(red->file));
    close(fd);
    return (0);
}

int double_redirect_left(redirect_s *red)
{
    char *cmd = NULL;
    size_t size = 0;
    int status = 0;

    while (status == 0) {
        my_putstr("> ");
        if (getline(&cmd, &size, stdin) == -1)
            return (84);
        if (strncmp(cmd, red->array[0], strlen(red->array[0])) == 0)
            break;
        red->cmd = push_back_list(red->cmd, cmd);
    }
    free(cmd);
    print_list(red->cmd);
    free_list(red->cmd);
    return (0);
}

char **do_redirect(char **array, redirect_s *redirect)
{
    redirect->type = check_redirect_tab(array);
    if (redirect->type == NO_REDIRECT || array == NULL)
        return (array);
    array = delete_redirect(array, redirect);
    redirect->file = get_file(redirect->array[0]);
    if (redirect->type == DREDIRECT_RIGHT ||
        redirect->type == REDIRECT_RIGHT)
        redirect_right(redirect);
    else {
        if (redirect->type == REDIRECT_LEFT)
            redirect_left(redirect);
        if (redirect->type == DREDIRECT_LEFT)
            double_redirect_left(redirect);
        if (redirect->pid == 0)
            exit(0);
    }
    return (array);
}
