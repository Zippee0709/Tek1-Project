/*
** EPITECH PROJECT, 2019
** minishell.c
** File description:
** minishell func
*/

#include "my.h"
#include "minishell.h"

void my_display_promp(void)
{
    my_putstr("$>");
}

int minishell(char **env)
{
    s_shell shell;

    shell.env = my_env_cpy(env);
    shell.path = my_get_path(env);
    my_display_promp();
    while ((shell.s = get_next_line(0)) != NULL) {
        shell.cmd = my_str_to_word_array(shell.s);
        shell.status = my_check_cmd(&shell);
        free(shell.s);
        my_check_status(shell.status);
        my_display_promp();
        
        /* my_check_string(shell.s); */
    }
    my_putchar('\n');
    /* my_free_all(&shell); */
    return (0);
}
