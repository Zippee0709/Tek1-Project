/*
** EPITECH PROJECT, 2019
** minishell header
** File description:
** header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

enum redirect
{
    NO_REDIRECT,
    REDIRECT_LEFT,
    REDIRECT_RIGHT,
    DREDIRECT_LEFT,
    DREDIRECT_RIGHT
};

typedef struct List_s
{
    char *str;
    struct List_s *next;
}List_t;

typedef struct redirect_t
{
    char **array;
    int type;
    char *file;
    List_t *cmd;
    pid_t pid;
}redirect_s;

int check_redirect_tab(char **array);
int check_redirect(char *array);
char **delete_redirect(char **array, redirect_s *redirect);
char *get_file(char const *str);

List_t *push_back_list(List_t *list, char *str);
List_t *pop_front_list(List_t *list);
void free_list(List_t *list);
void print_list(List_t *list);

void start_shell(char **env);
char **do_redirect(char **array, redirect_s *redirect);
void free_dtab(char **tab);
int check_no_command(char *command);
void quit(char *command);
char *check_access(char **arr);

void my_show_word_array(char **str);
int my_strdif(char *str1, char *str2);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s, char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *concat_params(char *str1, char *str2, char c);
char **my_str_to_word_array(char const *str, char c);
int str_contains(char *, char *);
void toomuch_arg(char **arr);
void notenough_arg(char *);
int count_char(char *, char);
void my_printf(char *str, ...);
char *my_strcat(char *dest, char const *src);
int space_handle(char *str, int *i, int *p);
void flag_string(char *str, int p);
void flag_nbr(int nb, int p);
void flag_char(int letter, int p);
int number(char *str);
int my_put_nbr(int nb);
int my_intlen(int nb);
char *my_revstr(char *str);
int is_targ(char *, char *);
void put_str_err(char *cmd, char *error);
int my_str_isalpha(char const *);

char **duplicate_env(char **env);
char **modify_env(char **env, char *path, char *old_path);
char *modify_pwd(char *env, char *path);
char *clean_buf(char *);
char **treat_buf(char *buf, char **env);
void treat_path(char *, char **);
char **do_command(char *buf, char **env);
char **print_env(char **env);
char **add_env(char **, char *);
char **delete_env(char **, char *);
char *add_char(char *, char);
char **delete_env(char **, char *);
int check_sign(char *);
char **treat_sign(char *, char **);
int check_segfault(int status, pid_t child);
char *not_dev(char *file);
char *strcpy_after(char *dest, char const *src, int *start);
char **do_setenv(char **, char **);

#endif
