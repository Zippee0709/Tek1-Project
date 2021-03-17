/*
** EPITECH PROJECT, 2019
** parse_cmd.c
** File description:
** parse_cmd.c
*/

#include "minishell.h"

static int my_strlen_size_cmd(char *str, int *j)
{
    int size = 0;

    while (str[*j] != '|' && str[*j] != ';' && str[*j] != '\0' &&
            str[*j] != '\n' && str[*j] != '\t') {
        *j = *j + 1;
        size++;
    }
    return (size);
}

static char **my_d_malloc_cmd(char *str, int size)
{
    int i = 0;
    int j = 0;
    int nb = 0;
    char **cmd = malloc(sizeof(char *) * (size + 1));

    if (cmd == NULL)
        return (NULL);
    while (i < size) {
        if (str[j] == ';' || str[j] == '|')
            j++;
        nb = my_strlen_size_cmd(str, &j);
        cmd[i] = malloc(sizeof(char) * (nb + 1));
        if (cmd[i] == NULL)
            return (NULL);
        i++;
    }
    cmd[i] = NULL;
    return (cmd);
}

static char **my_fill_tab_cmd(char *str, char **cmd)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == ';' || str[i] == '|') {
            cmd[j][k] = '\0';
            j = j + 1;
            k = 0;
        } else {
            cmd[j][k] = str[i];
            k = k + 1;
        }
        i++;
    }
    cmd[j][k] = '\0';
    return (cmd);
}

static int my_strlen_nb_cmd(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == ';' || str[i] == '|' || str[i] == '\n')
            nb++;
        i++;
    }
    nb++;
    return (nb);
}

char **my_str_to_word_cmd(char *str)
{
    int size = my_strlen_nb_cmd(str);
    char **cmd = my_d_malloc_cmd(str, size);

    if (cmd == NULL)
        return (NULL);
    cmd = my_fill_tab_cmd(str, cmd);
    cmd = my_clean_tab_str(cmd);
    return (cmd);
}
