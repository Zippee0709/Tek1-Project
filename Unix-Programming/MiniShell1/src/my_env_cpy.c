/*
** EPITECH PROJECT, 2019
** my_env_cpy.c
** File description:
** my_env_cpy func
*/

#include "my.h"
#include "minishell.h"

int my_strlen_dtab_size(char **env)
{
    int	i = 0;

    while (env[i] != NULL)
        i = i +	1;
    return (i);
}

char *my_env_fill_malloc(char *str)
{
    int size = my_strlen(str);
    char *cpy = malloc(sizeof(char) * (size + 1));

    if (cpy == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        exit(EXIT_ERROR);
    }
    size = 0;
    while (str[size] != '\0') {
        cpy[size] = str[size];
        size = size + 1;
    }
    cpy[size] = '\0';
    return (cpy);
}

char **my_env_cpy(char **env)
{
    int	i = 0;
    int	size = my_strlen_dtab_size(env);
    char **cpy = malloc(sizeof(char * ) * (size + 1));

    if (cpy == NULL) {
	my_putstr_err("Error : Allocation memory failed !\n");
        exit(EXIT_ERROR);
    }
    while (i < size) {
	cpy[i] = my_env_fill_malloc(env[i]);
        i = i +	1;
    }
    cpy[i] = NULL;
    return (cpy);
}


