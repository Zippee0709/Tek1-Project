/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** errors.c
*/

#include "my_rpg.h"

static int cmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1 && s2 && s1[i] == s2[i])
        if (!s1[i++] || i == n)
            return (SUCCESS);
    return (FAILURE);
}

int errors(char *envp[])
{
    for (int a = 0; envp[a] != NULL; a++)
        if (cmp(envp[a], "DISPLAY=", 8) == SUCCESS)
            return (SUCCESS);
    write(2, "Environment variable 'DISPLAY' is missing.\n", 43);
    return (FAILURE);
}
