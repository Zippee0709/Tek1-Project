/*
** EPITECH PROJECT, 2019
** minishell.h
** File description:
** minishell.h
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#define ERROR 84
#define SUCCESS 0
#define FAILED 1

#include "gnl.h"
#include "my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

typedef enum redirect
{
    NO_REDIRECT,
    REDIRECT_LEFT,
    REDIRECT_RIGHT,
    DREDIRECT_LEFT,
    DREDIRECT_RIGHT
}redirect;

typedef struct DlistNode
{
    char *str;
    struct DlistNode *back;
    struct DlistNode *next;
}DlistNode;

typedef struct Dlist_t
{
    int length;
    DlistNode *begin;
    DlistNode *end;
}Dlist_t;

typedef struct DlistElement
{
    char **cmd;
    struct DlistElement *back;
    struct DlistElement *next;
}DlistElement;

typedef struct Dlist_cmd
{
    int length;
    DlistElement *begin;
    DlistElement *end;
}Dlist_cmd;

typedef struct Pompt_t
{
    char *name;
    char *host;
    char *pwd;
}Pompt_t;

typedef struct redirect_t
{
    int type;
    pid_t pid;
    char *file;
    char **array;
    Dlist_t *cmd;
}redirect_t;

typedef struct Shell_t
{
    Dlist_t *env;
    Dlist_cmd *cmd;
    char *str;
    char **path;
    char *full_path;
    char **env_tab;
    redirect_t redi;
    int status;
}Shell_t;

/*--------------------init.c--------------------*/
int my_init_shell(Shell_t *shell, char **env);

/*--------------------shell.c--------------------*/
int minishell(Shell_t *shell);

/*--------------------clean_str.c--------------------*/
char *clean_str(char *str);

/*--------------------copy_env.c--------------------*/
Dlist_t *copy_double_tab_in_list(Dlist_t *list, char **tab);
char **copy_list_in_double_tab(Dlist_t *list);

/*--------------------list.c--------------------*/
Dlist_t *push_back_dlist(Dlist_t *list, char *str);
Dlist_t *pop_back_dlist(Dlist_t *list);
Dlist_t *pop_begin_dlist(Dlist_t *list);

/*--------------------list_cmd.c--------------------*/
Dlist_cmd *pop_back_cmd_dlist(Dlist_cmd *list);
Dlist_cmd *split_cmd_in_dlist(Dlist_cmd *order, char *str);

/*--------------------parse_cmd.c--------------------*/
char **my_str_to_word_cmd(char *str);

/*--------------------clean_cmd.c--------------------*/
char **my_clean_tab_str(char **tab);

/*--------------------check_cmd.c--------------------*/
int check_cmd(Shell_t *shell);

/*--------------------execution.c--------------------*/
int check_access(Shell_t *shell, char **cmd);
void my_put_error_access(char *cmd, char *str);
void my_exec(Shell_t *shell, char *full_path, char **cmd);

/*--------------------array_tab.c--------------------*/
char **my_str_to_word_tab(char const *str, char c);

/*--------------------change_directory.c--------------------*/
int my_check_directory(Shell_t *shell, char **cmd);

/*--------------------setenv.c--------------------*/
void my_unsetenv(Shell_t *shell, char *env);
void my_setenv(Shell_t *shell, char *name, char *env);

/*--------------------getenv.c--------------------*/
char *my_get_env(Dlist_t *list, char *env);

/*--------------------func.c--------------------*/
int my_strcmp_begin(char *s1, char *s2);
char *my_str_char_cpy(char *dest, char *src, char c, int i);
char *my_clean_str(char *str, char c);
char *my_clean_pwd(char *str, char c);
char *my_clean_path(char *str, char c);

/*--------------------redirect.c--------------------*/
char **do_redirect(char **cmd, redirect_t *redir);
char *get_file(char const *file);

/*--------------------check_redir.c--------------------*/
int check_redirect_tab(char **array);
char **delete_redirect(char **array, redirect_t *redirect);
int check_redirect(char *array);

/*--------------------func_list.c--------------------*/
void print_list(Dlist_t *list);
void print_list_cmd(Dlist_cmd *list);
void free_list_cmd(Dlist_cmd *list);
void free_list(Dlist_t *list);

/*--------------------str_concat.c--------------------*/
char *my_str_concat(char *s1, char *s2);
char *my_str_concat_c(char *s1, char *s2, char *c);

/*--------------------free.c--------------------*/
void my_free_dtab(char **tab);
void my_free_shell(Shell_t *shell);



#endif
