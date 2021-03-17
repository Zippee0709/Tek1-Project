/*
** EPITECH PROJECT, 2019
** minihsell.h
** File description:
** all usefull protoypes and struct data for minishell
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#define EXIT_ERROR 84
#define SUCCESS 1

#include "gnl.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_shell
{
    char *s;
    char *full_path;
    char **cmd;
    char **path;
    char **env;
    int status;
}s_shell;

int minishell(char **env);

int my_get_path_size(char *path);
char **my_get_path(char **env);

int my_check_builtins(char **env, char **cmd);
int my_check_cmd(s_shell *shell);
void my_check_status(int status);
void my_check_string(char *str);

void my_execution(s_shell *shell, char *full_path, pid_t pid);

char **my_env_cpy(char **env);
char *my_str_concat(char *s1, char *s2);

char **my_str_to_word_tab(char const *str, char c);

void my_free_dtab(char **tab);
void my_free_all(s_shell *shell);
#endif
