/*
** EPITECH PROJECT, 2019
** main_shell
** File description:
** start_shell
*/

#include "../include/minishell.h"

static char *fill_buf(char *buf, int size)
{
    char *input = malloc(sizeof(char) * size + 1);
    int i = 0;
    int a = 0;

    if (input == NULL)
        exit(84);
    while (buf[i] != '\0') {
        if ((buf[i] == ' ' && buf[i + 1] == ' ') ||
            (buf[i] == ' ' && buf[i + 1] == ';') ||
            (buf[i] == ' ' && buf[i + 1] == '\n') || (buf[i] == '\n'))
            i = i + 1;
        else {
            input[a] = buf[i];
            a = a + 1;
            i = i + 1;
        }
    }
    input[a] = '\0';
    if (input[0] == ' ')
        return (&input[1]);
    return (input);
}

static char *delete_tabs(char *buf)
{
    int i = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '\t')
            buf[i] = ' ';
        i = i + 1;
    }
    return (buf);
}

char *clean_buf(char *buf)
{
    int i = 0;
    int count = 0;
    int size;

    buf = delete_tabs(buf);
    while (buf[i] != '\0') {
        if ((buf[i] == ' ' && buf[i + 1] == '\n') ||
            (buf[i] == ' ' && buf[i + 1] == ' ') ||
            (buf[i] == ' ' && buf[i + 1] == ';'))
            count = count + 1;
        i = i + 1;
    }
    size = my_strlen(buf) - count + 1;
    return (fill_buf(buf, size));
}

void start_shell(char **env)
{
    char *buf = NULL;
    size_t size;
    ssize_t value = 2;

    while (value > 1) {
        do {
            my_putstr("$> ");
            if (getline(&buf, &size, stdin) == -1)
                quit("exit");
        } while (check_no_command(buf) == 0);
        buf = clean_buf(buf);
        if (my_strcmp(buf, "exit") == 0)
            quit("exit");
        env = treat_buf(buf, env);
        free(buf);
        buf = NULL;
    }
}
