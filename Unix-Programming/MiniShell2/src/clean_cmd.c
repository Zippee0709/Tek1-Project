/*
** EPITECH PROJECT, 2019
** my_clean_cmd.c
** File description:
** my_clean_cmd.c
*/

#include "my.h"
#include "minishell.h"

static int my_check_char_cmd(char a, char b)
{
    if ((a == ' ' && b != ' ' && b != ';' && b != '|' && b != '\0'))
        return (0);
    return (1);
}

static int my_strlen_clean_str(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] == ' ' && str[i] != '\0')
        i++;
    while (str[i] != '\0') {
        if (my_check_char_cmd(str[i], str[i + 1]) == 0 || str[i] != ' ')
            nb++;
        i++;
    }
    return (nb);
}

char *my_clean_str_cmd(char *str)
{
    int j = 0;
    int i = my_strlen_clean_str(str);
    char *cpy = malloc(sizeof(char) * (i + 1));

    i = 0;
    while (str[i] == ' ')
        i++;
    while (str[i] != '\0') {
        if (my_check_char_cmd(str[i], str[i + 1]) == 0 || str[i] != ' ') {
            cpy[j] = str[i];
            j++;
        }
        i++;
    }
    cpy[j] = '\0';
    free(str);
    return (cpy);
}

char **my_clean_tab_str(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        tab[i] = my_clean_str_cmd(tab[i]);
        i++;
    }
    return (tab);
}
