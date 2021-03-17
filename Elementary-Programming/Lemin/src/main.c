/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for lem in
*/

#include "lemin.h"
#include "my.h"

int my_init_lemin(Global_t *global, Error_t *error)
{
    global->file = read_file_with_getline(0);
    if (global->file == NULL || global->file[0] == '\0')
        return (84);
    global->tab = my_str_to_word_tab(global->file, '\n');
    global->tab = my_clean_tab(global->tab);
    my_init_new_graph(global);
    if (global->start == -1 || global->end == -1 || global->nb_ants <= 0 ||
        global->tunnels == NULL)
        return (84);
    my_show_file(global->tab);
    return (0);
}

int main(int ac, char **av)
{
    Global_t global;
    Error_t *error = malloc(sizeof(*error));

    if (my_init_lemin(&global, error) == 84) {
        free(error);
        return (84);
    }
    free(error);
    return (0);
}
