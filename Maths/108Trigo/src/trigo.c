/*
** EPITECH PROJECT, 2019
** trigo.c
** File description:
** trigo.c
*/

#include "trigo.h"

int my_check_fun_type(char **tab, char *type)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strcmp(tab[i], type) == 0)
            return (i);
        i++;
    }
    return (-1);
}

int can_leave(Global_t *global, float *current)
{
    if (equal_mat(global->result, current, global->length)) {
        return (1);
    }
    if (empty_mat(global->result, global->length)) {
        copy_mat(global->result, current, global->length);
        return (1);
    }
    return (0);
}

void my_trigo(Global_t *global)
{
    int i = my_check_fun_type(global->tab_type, global->type);
    tpsf tab[5] = {my_exp, my_cos, my_sin, my_cosh, my_sinh};

    if (i == -1) {
        my_free_all(global);
        exit(EXIT_FAIL);
    }
    (*tab[i])(global);
    display_float_tab(global->result, global->size);
}
