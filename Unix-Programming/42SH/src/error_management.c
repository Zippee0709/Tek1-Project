/*
** EPITECH PROJECT, 2019
** error_management.c
** File description:
** error handling
*/

#include <sys/types.h>
#include <dirent.h>
#include "../include/minishell.h"

int check_segfault(int status, pid_t child)
{
    int sig = WTERMSIG(status);

    if (sig == SIGFPE)
        my_putstr("Floating exception");
    if (sig == SIGSEGV)
        my_putstr("Segmentation fault");
    if (WCOREDUMP(status)) {
        kill(child, SIGSEGV);
        my_putstr(" (core dumped)\n");
        status = 0;
    } else if (sig != 0)
        my_putchar('\n');
    return status;
}

char *not_dev(char *file)
{
    DIR *is_dir;

    is_dir = opendir(file);
    if (is_dir != NULL) {
        my_printf("%s: Permission denied.\n", file);
        closedir(is_dir);
        return NULL;
    }
    closedir(is_dir);
    if (my_strlen(file) > 2) {
        if (file[0] == '.' && file[1] == '/' && access(&file[2], X_OK) != -1)
            return (&file[2]);
    }
    if (access(file, X_OK) != -1)
        return file;
    else
        my_printf("%s: Command not found.\n", file);
    return NULL;
}

int check_no_command(char *command)
{
    int i = 0;

    while (command[i] != '\0') {
        if (command[i] != ' ' && command[i] != '\n' && command[i] != '\t')
            return 1;
        i++;
    }
    return 0;
}
