/*
** EPITECH PROJECT, 2019
** check_redirect.c
** File description:
** check_redirect.c
*/

#include "../include/minishell.h"

char **delete_redirect(char **array, redirect_t *redirect)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (; check_redirect(array[i]) == 0 && array[i] != NULL; i++);
    for (j = i; array[j] != NULL; j++);
    redirect->array = malloc(sizeof(char *) * (j - i - 1 + 1));
    for (j = i + 1, k = 0; array[j] != NULL; j++, k++)
        redirect->array[k] = my_strdup(array[j]);
    redirect->array[k] = NULL;
    for (k = i + 1; array[k] != NULL; k++)
        free(array[k]);
    array[i] = NULL;
    return (array);
}

int check_redirect(char *array)
{
    if (my_strcmp(array, "<<") == 0)
        return (DREDIRECT_LEFT);
    if (my_strcmp(array, ">>") == 0)
        return (DREDIRECT_RIGHT);
    if (my_strcmp(array, "<") == 0)
        return (REDIRECT_LEFT);
    if (my_strcmp(array, ">") == 0)
        return (REDIRECT_RIGHT);
    return (NO_REDIRECT);
}

int check_redirect_tab(char **array)
{
    int i = 0;
    int status = 0;

    for (i = 0; array[i] != NULL; i++) {
        status = check_redirect(array[i]);
        if (status > 0)
            return (status);
    }
    return (status);
}
