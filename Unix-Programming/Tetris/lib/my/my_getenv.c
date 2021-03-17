/*
** EPITECH PROJECT, 2019
** my_getenv.c
** File description:
** getenv
*/

#include <stddef.h>

int my_strlen(char const *str);
int my_strncmp(char *str, char *str2, int n);

char *remove_title(char *res, int len)
{
    int i = 0;

    while (i < len + 1) {
        res++;
        i++;
    }
    return (res);
}

char *my_getenv(char *envp[], char *str)
{
    int lenstr = my_strlen(str);

    if (envp == NULL)
        return (NULL);
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(str, envp[i], lenstr) == 0) {
            return (remove_title(envp[i], lenstr));
        }
    }
    return (NULL);
}
