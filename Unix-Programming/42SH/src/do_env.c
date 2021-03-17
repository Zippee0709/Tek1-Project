/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** set and unset env
*/

#include "minishell.h"

char *replace_line(char *line, char *entr, char *value)
{
    line = malloc(sizeof(char) * (my_strlen(entr) + my_strlen(value) + 2));
    line = my_strcpy(line, entr);
    line = my_strcat(line, "=");
    line = my_strcat(line, value);
    if (value[0] != '\0')
        line[my_strlen(line)] = '\0';
    free(entr);
    return (line);
}

char **add_line(char **env, char *entr, char *add)
{
    char **new_env = NULL;
    int size = 0;

    for (; env[size]; size++);
    new_env = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; env[i]; i++) {
        new_env[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        new_env[i] = my_strcpy(new_env[i], env[i]);
    }
    new_env[size] = replace_line(new_env[size], entr, add);
    new_env[size + 1] = NULL;
    return (new_env);
}

char **check_setenv(char **env, char **entry, int size)
{
    int check = 0;

    if (size == 2) {
        for (int i = 0; env[i] && check == 0; i++)
            if (is_targ(entry[1], env[i]) == 0) {
                env[i] = replace_line(env[i], entry[1], "\0");
                check++;
            }
        if (check == 0)
            env = add_line(env, entry[1], "\0");
    } else {
        for (int i = 0; env[i] && check == 0; i++)
            if (is_targ(entry[1], env[i]) == 0) {
                env[i] = replace_line(env[i], entry[1], entry[2]);
                check++;
            }
        if (check == 0)
            env = add_line(env, entry[1], entry[2]);
    }
    return (env);
}

char **do_setenv(char **entry, char **env)
{
    int size = 0;

    for (; entry[size]; size++);
    if (size > 3) {
        put_str_err(entry[0], ": Too many arguments.\n");
        return (env);
    } else if (size > 1 && my_str_isalpha(entry[1]) == 0) {
        put_str_err(entry[0], ": Variable name must begin with a letter.\n");
        return (env);
    }
    if (size == 1)
        for (int i = 0; env[i]; my_putstr(env[i]), my_putchar('\n'), i++);
    else if (size >= 2) {
        env = check_setenv(env, entry, size);
    }
    return (env);
}
