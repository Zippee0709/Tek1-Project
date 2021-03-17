/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get function
*/

#include "my.h"
#include "minishell.h"

static char *my_str_del_path(char *str, int size)
{
    int i = my_strlen(str) - size;
    char *cpy = malloc(sizeof(char) * (i + 1));

    if (cpy == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        return (NULL);
    }
    i = 0;
    while (str[size] != '\0') {
        cpy[i] = str[size];
        size = size + 1;
        i = i + 1;
    }
    cpy[i] = '\0';
    free(str);
    return (cpy);
}

char *my_get_env(Dlist_t *list, char *env)
{
    char *str = NULL;
    DlistNode *tmp = NULL;

    if (list == NULL)
        return (NULL);
    tmp = list->begin;
    while (tmp != NULL) {
        if (my_strcmp_begin(tmp->str, env) == 0) {
            str = my_strdup(tmp->str);
            str = my_str_del_path(str, my_strlen(env));
            return (str);
        }
        tmp = tmp->next;
    }
    return (NULL);
}
