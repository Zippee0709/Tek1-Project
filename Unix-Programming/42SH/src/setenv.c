/*
** EPITECH PROJECT, 2019
** builtins environment
** File description:
** minishell
*/

#include "../include/minishell.h"

char **print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i = i + 1;
    }
    return (env);
}

static int check_parse(char **parse)
{
    int count = 1;

    for (; parse[count]; count++);
    if (count > 2) {
        my_putstr("Too many arguments.\n");
        return (count);
    } else
        return (count);
}

static char **fill_bis(char **env, char **bis, int size)
{
    int i = 0;

    while (i != size) {
        bis[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        if (bis[i] == NULL)
            exit(84);
        bis[i] = my_strcpy(bis[i], env[i]);
        i = i + 1;
    }
    return (bis);
}

char **add_env(char **env, char *buf)
{
    int size = 0;
    char **bis;
    char **parse = my_str_to_word_array(buf, ' ');
    int count = check_parse(parse);

    if (count > 2) {
        free(parse);
        return (env);
    }
    for (; env[size]; size++);
    bis = malloc(sizeof(char *) * (size + 2));
    bis = fill_bis(env, bis, size);
    if (count == 1)
        bis[size] = add_char(parse[0], '=');
    else
        bis[size] = concat_params(parse[0], parse[1], '=');
    bis[size + 1] = NULL;
    free(env);
    free(parse);
    return (bis);
}
