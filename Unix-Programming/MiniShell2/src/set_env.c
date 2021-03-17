/*
** EPITECH PROJECT, 2019
** set_env.c
** File description:
** set_env.c
*/

#include "my.h"
#include "minishell.h"

static int my_unset_begin_or_back(Shell_t *shell, DlistNode *tmp)
{
    if (tmp->next == NULL) {
        shell->env = pop_back_dlist(shell->env);
        return (0);
    }
    else if (tmp->back == NULL) {
        shell->env = pop_begin_dlist(shell->env);
        return (0);
    }
    return (1);
}

void my_unsetenv(Shell_t *shell, char *env)
{
    DlistNode *tmp;

    if (shell->env == NULL || env == NULL)
        return;
    tmp = shell->env->begin;
    while (tmp != NULL) {
        if (my_strcmp_begin(tmp->str, env) == 0) {
            if (my_unset_begin_or_back(shell, tmp) == 0)
                return;
            tmp->back->next = tmp->next;
            tmp->next->back = tmp->back;
            free(tmp->str);
            free(tmp);
            return;
        }
        tmp = tmp->next;
    }
}

void my_setenv(Shell_t *shell, char *name, char *env)
{
    DlistNode *tmp = NULL;
    char *path = NULL;

    if (name == NULL)
        return;
    path = my_str_concat(name, "=");
    if (env != NULL)
        path = my_str_concat(path, env);
    if (shell->env != NULL)
        tmp = shell->env->begin;
    while (tmp != NULL) {
        if (my_strcmp_begin(tmp->str, name) == 0) {
            free(tmp->str);
            tmp->str = my_strdup(path);
            return;
        }
        tmp = tmp->next;
    }
    shell->env = push_back_dlist(shell->env, path);
}
